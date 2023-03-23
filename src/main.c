/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtaravel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 21:56:56 by jtaravel          #+#    #+#             */
/*   Updated: 2023/03/23 17:49:16 by jtaravel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wordle.h"
#include <readline/readline.h>
#include <readline/history.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

void	free_tab(char **tab)
{
	int	i = 0;
	while (tab && tab[i])
	{
		free(tab[i]);
		i++;
	}
	if (tab)
	{
		free(tab);
		tab = NULL;
	}
}

int	is_lastchr(char *str, char c)
{
	int	i = 0;

	while (str && str[i])
		i++;
	i--;
	if (str && i >= 0 && str[i] && str[i] == c)
		return (1);
	return (0);
}

int	is_word_ok(char *str)
{
	int	len;
	int	i;

	if (!str)
		return (0);
	len = ft_strlen(str);
	if ((len == 6 && str[len - 1] == '\n') || (len == 5 && str[len - 1] != '\n'))
	{
		i = 0;
		while (i < len && str[i] != '\n')
		{
			if (!ft_isalpha(str[i]))
				return (0);
			i++;
		}
		return (1);
	}
	return (0);
}

int	ft_dico_size(char *filename)
{
	int		size;
	char	*line;
	int		fd = 0;
	int		len_line;

	size = 0;
	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return (perror(filename), -1);
	while ((line = get_next_line(fd)) != NULL)
	{
		len_line = ft_strlen(line);
		if (is_word_ok(line))
			size++;
		free(line);
		line = NULL;
	}
	if (line == NULL)
		get_next_line(-1);
	if (close(fd) == -1)
		return (FAILURE);
	if (size == 0)
		fprintf(stderr, "No words matching prerequisites in this file: %s.\n", filename);
	return (size);
}

void	print_tab(char **tab)
{
	int	i = 0;
	while (tab && tab[i])
	{
		fprintf(stderr, "%s\n", tab[i]);
		i++;
	}
}

int	is_dir(const char *filename)
{
	struct stat	statbuf;
	int			isdir;

	memset(&statbuf, 0, sizeof(statbuf));
	if (stat(filename, &statbuf) != 0)
		return (0);
	isdir = S_ISDIR(statbuf.st_mode);
	return (isdir);
}

int	get_dico(char ***dico, int *dico_size, char *filename)
{
	int	fd = 0;
	int	i = 0;
	char	*line;
	int		len_line;

	if (is_dir(filename))
		return (errno = 21, perror(filename), FAILURE);
	else if (access(filename, F_OK | R_OK) != 0)
		return (perror(filename), FAILURE);
	*dico_size = ft_dico_size(filename);
	if (*dico_size <= 0)
		return (FAILURE);
	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return (perror("opening failed"), FAILURE);
	*dico = malloc(sizeof(char *) * (*dico_size + 1));
	if (!(*dico))
		return (FAILURE);
	while (i < *dico_size)
	{
		line = get_next_line(fd);
		if (!line)
			return (free_tab(*dico), get_next_line(-1), FAILURE);
		len_line = ft_strlen(line);
		if (is_word_ok(line))
		{
			(*dico)[i] = line;
			i++;
		}
		else
			free(line);
	}
	(*dico)[i] = NULL;
	if (close(fd) == -1)
		return (free_tab(*dico), perror("closing failed"), FAILURE);
	return (SUCCESS);
}

int	input_isok(char *str, char **dico)
{
	int		i = 0;

	if (!str || ft_strlen(str) != 5)
		return (fprintf(stderr, "\033[91mWRONG SIZE\n\033[37m"), 0);
	while (dico && dico[i])
	{
		if (strncasecmp(str, dico[i], 5) == 0)
			return (1);
		i++;
	}
	return (fprintf(stderr, "\033[91mNOT IN DICTIONARY\n\033[37m"), 0);
}

void	print_trys(t_c *trys)
{
	int		lines = 0;
	int		i = 0;

	fprintf(stderr, "\033[37m\n\t\t\t________________________\n");
	while (trys)
	{
		fprintf (stderr, "\t\t\t\t");
		i = 0;
		while (i < 6)
		{
			if (trys->colors[i] == green)
				fprintf(stderr, "\033[92m%c \033[37m", trys->strtry[i]);
			else if (trys->colors[i] == orange)
				fprintf(stderr, "\033[93m%c \033[37m", trys->strtry[i]);
			else if (trys->colors[i] == grey)
				fprintf(stderr, "\033[90m%c \033[37m", trys->strtry[i]);
			i++;
		}
		fprintf(stderr, "\033[97m\n\033[37m");
		trys = trys->next;
		lines++;
	}
	while (lines < 6)
	{
		fprintf (stderr, "\t\t\t\t");
		fprintf(stderr, "_ _ _ _ _\n");
		lines++;
	}
	fprintf(stderr, "\t\t\t________________________\n");
}

int	is_chrcasecmp(char c1, char c2)
{
	if (c1 == c2)
		return (1);
	if (c1 >= 'A' && c1 <= 'Z')
	{
		if (c2 == c1 + 32)
			return (1);
	}
	if (c2 >= 'A' && c2 <= 'Z')
	{
		if (c1 == c2 + 32)
			return (1);
	}
	return (0);
}

int occurences(t_c *new_try, char *tofind, char c)
{
	int		i = 0;
	int		nb = 0;

	while (i < 6)
	{
		if (is_chrcasecmp(c, tofind[i]))
			nb++;
		i++;
	}
	i = 0;
	while (i < 6)
	{
		if (is_chrcasecmp(new_try->strtry[i], c) && new_try->colors[i] != grey)
			nb--;
		i++;
	}
	return (nb);
}

void set_orange(t_c *new_try, char *tofind)
{
	int		i = 0;
	int		nb_occur_last;
	char	*str;

	str = new_try->strtry;
	while (i < 6)
	{
		nb_occur_last = occurences(new_try, tofind, str[i]);
		if (new_try->colors[i] == grey && ft_strcasechr(tofind, str[i]) != NULL
		&& nb_occur_last >= 1)
		{
			new_try->colors[i] = orange;
			nb_occur_last--;
		}
		i++;
	}
}

void set_colors(t_c *new_try, char *tofind)
{
	int		i;
	char	*str;

	str = new_try->strtry;
	i = 0;
	while (i < 6)
	{
		if (is_chrcasecmp(tofind[i], str[i]))
			new_try->colors[i] = green;
		i++;
	}
	set_orange(new_try, tofind);
}

void	ft_print_wordle(void)
{
	printf("\t \033[35m/$$      /$$  /$$$$$$  /$$$$$$$  /$$$$$$$  /$$      /$$$$$$$$ \n \
	| $$  /$ | $$ /$$__  $$| $$__  $$| $$__  $$| $$      | $$_____/	\n \
	| $$ /$$$| $$| $$  \\ $$| $$  \\ $$| $$  \\ $$| $$      | $$ \n \
	| $$/$$ $$ $$| $$  | $$| $$$$$$$/| $$  | $$| $$      | $$$$$   \n \
	| $$$$_  $$$$| $$  | $$| $$__  $$| $$  | $$| $$      | $$__/   \n \
	| $$$/ \\  $$$| $$  | $$| $$  \\ $$| $$  | $$| $$      | $$ \n \
	| $$/   \\  $$|  $$$$$$/| $$  | $$| $$$$$$$/| $$$$$$$$| $$$$$$$$\n \
	|__/     \\__/ \\______/ |__/  |__/|_______/ |________/|________/\n\033[37m");
}

int	ft_ismincase(char c)
{
	if (c >= 'a' && c <= 'z')
		return (1);
	return (0);
}

void	ft_uppercase(char *str)
{
	int		i = 0;

	while (str && str[i])
	{
		if (ft_ismincase(str[i]))
			str[i] = str[i] - 32;
		i++;
	}
}

char	*chose_word(char **dico, int dico_size)
{
	int		nb = 0;

	srand(time(NULL));
	nb = rand() % (dico_size);
	return (dico[nb]);
}

void	print_keyboard(t_c keyboard)
{
	int		i = 0;
	char	*str;

	str = keyboard.strtry;
	fprintf(stderr, "\t\t\t\t");
	while (str && str[i])
	{
		if (keyboard.colors[i] == green)
			fprintf(stderr, "\033[92m%c\033[37m", keyboard.strtry[i]);
		else if (keyboard.colors[i] == orange)
			fprintf(stderr, "\033[93m%c\033[37m", keyboard.strtry[i]);
		else if (keyboard.colors[i] == grey)
			fprintf(stderr, "\033[90m%c\033[37m", keyboard.strtry[i]);
		else
			fprintf(stderr, "\033[37m%c\033[37m", keyboard.strtry[i]);
		if (i != 0 && i != 24 && i % 8 == 0)
			fprintf(stderr, "\n\t\t\t\t");
		i++;
	}
	fprintf(stderr, "\n");
}

void	set_keyboard_colors(t_c *keyboard, t_c *new_try)
{
	int	i = 0;
	int	j = 0;
	char	*str;

	str = new_try->strtry;
	while (str && str[i])
	{
		j = 0;
		while (keyboard->strtry[j] != str[i] && j < 26)
			j++;
		if (keyboard->colors[j] == white || new_try->colors[i] == green)
			keyboard->colors[j] = new_try->colors[i];
		i++;
	}
}

t_c	*init_keyboard(void)
{
	int	i = 0;
	int	alpha = 65;
	char	*str;
	int		*colors;
	t_c		*keyboard;

	str = malloc(sizeof(char) * (26 + 1));
	if (!str)
		return (NULL);
	colors = malloc(sizeof(int) * (26 + 1));
	if (!colors)
		return (free(str), NULL);
	while (i < 26)
	{
		str[i] = alpha + i;
		colors[i] = white;
		i++;
	}
	str[i] = 0;
	keyboard = ft_new_try(str, colors);
	if (!keyboard)
		return (free(str), free(colors), NULL);
	return (keyboard);
}

int	main(int argc, char **argv)
{
	char	**dico;
	t_c		*trys;
	t_c		*keyboard = NULL;
	t_c		*new_try;
	char	*input;
	char	*tofind;
	int		try_max = 0;
	int		dico_size = 0;
	
	signal(SIGQUIT, SIG_IGN);
	signal(SIGINT, SIG_IGN);
	ft_print_wordle();
	dico = NULL;
	trys = NULL;
	if (argc == 1)
		get_dico(&dico, &dico_size, DICO_DFLT);
	else if (argc != 2)
		return (fprintf(stderr, "Wrong number of arguments\n"), 1);
	else if (get_dico(&dico, &dico_size, argv[1]) == FAILURE)
				return (1);
	tofind = chose_word(dico, dico_size);
	keyboard = init_keyboard();
	if (!keyboard)
		return (free_tab(dico), 1);
	print_trys(trys);
	print_keyboard(*keyboard);
	while (try_max < 6)
	{
		input = readline("> your guess: ");
		if (!input)
		{
			printf("\n");
			return (free_tab(dico), try_lst_free(trys), try_lst_free(keyboard), 1);
		}
		if (input_isok(input, dico))
		{
			ft_uppercase(input);
			new_try = ft_new_try(input, NULL);
			if (!new_try)
				return (try_lst_free(trys), free(input), free_tab(dico), try_lst_free(keyboard), 1);
			try_addback(&trys, new_try);
			set_colors(new_try, tofind);
			set_keyboard_colors(keyboard, new_try);
			if (!strncasecmp(tofind, new_try->strtry, 5))
			{
				print_trys(trys);
				print_keyboard(*keyboard);
				fprintf(stderr, "\t\t\t\033[92m    YOU WIN IN %d GUESS\n\033[37m", try_max + 1);
				return (free_tab(dico), try_lst_free(trys), try_lst_free(keyboard), 0);
			}
			try_max++;
		}
		print_trys(trys);
		print_keyboard(*keyboard);
	}
	ft_uppercase(tofind);
	if (tofind[5] == '\n')
		tofind[5] = 0;
	fprintf(stderr, "\t\t\t\033[91mYOU LOOSE, THE WORD WAS \033[92m%s\n\033[37m", tofind);
	try_lst_free(trys);
	free_tab(dico);
	try_lst_free(keyboard);
	return (0);
}
