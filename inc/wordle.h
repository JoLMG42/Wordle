/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wordle.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtaravel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 22:29:48 by jtaravel          #+#    #+#             */
/*   Updated: 2022/05/15 18:17:34 by cdefonte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WORDLE_H
#	define WORDLE_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/types.h>
# include <signal.h>
# include <sys/stat.h>
# include <fcntl.h>

# include "libft.h"
# ifndef FAILURE
#	define FAILURE 0
# endif
# ifndef SUCCESS
# define SUCCESS 1
# endif
# ifndef DICO_DIR
# define DICO_DIR "dicos/"
# endif
# ifndef DICO_DFLT
# define DICO_DFLT "dicos/dico.txt"
# endif

typedef enum e_colors {grey, orange, green, white} t_colors;

typedef struct t_char
{
	int				*colors;
	char			*strtry;
	struct t_char	*next;
}	t_c;

t_c		*ft_new_try(char *str, int *colors);
void	try_lst_free(t_c *lst);
void	try_addback(t_c **alst, t_c *new);

#endif
