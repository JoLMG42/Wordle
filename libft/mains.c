/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mains.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdefonte <cdefonte@student42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 09:45:52 by cdefonte          #+#    #+#             */
/*   Updated: 2022/02/05 15:46:00 by cdefonte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// MEMSET permet de remplir une zone mémoire, identifiée par son adresse et 
// sa taille, avec une valeur précise.
//int     main(void)
//{
//        char    s[] = "PouetPouet";
//
//        memset(s, '.', sizeof(char) * 3);
//        printf("Retour bibi: %s\n", s);
//        return (0);
//}

// BZERO
//int     main(void)
//{
//        void *b;
//        char s[6] = {'P', 'o', 'u', 'e', 't', '!'};
//
//        b = s;
//        // Affichage de la chaine avant fct
//        int i = 0;
//        while (i < 6)
//        {
//                write(1, &s[i], 1);
//                i++;
//        }
//        write(1, "\n", 1);
//
//        //Rajouter/enlever "ft_" ici pour comparer les résultats officielle/bibi
//        ft_bzero(b, 3);
//
//        //Affichage apres la fct
//        i = 0;
//        while (i < 6)
//        {
//                write(1, &s[i], 1);
//                i++;
//        }
//        write(1, "\n", 1);
//        return (0);
//}
//

// MEMCPY
//int   main(void)
//{
//      char d[] = "Ah!";
//      const char s[] = ""; 
//      printf("dest avant: %s\n", d);
//// Modif ici pour test officielle/bibi:
//      ft_memcpy(d, s, 2);
//      printf("dest apres: %s\n", d);
//      return (0);
//}


// MEMMOVE
//int     main(void)
//{
//        char    d[] = "Pouet";
//        
//        printf("Source: %s\n", d);
//        printf("Dest: %s\n", d + 2);
//        ft_memmove(d + 2, d, 3);
//        printf("dest apres: %s\n", d  + 2);
//        return (0);
//}

// STRLCPY
//int     main(void)
//{
//        char            dst[] = "Pouet";
//        const char      src[] = "";
//        size_t          size = 5;
//
//        printf("%s\n", src);
//        printf("%s\n", dst);
//        printf("%zu\n", ft_strlcpy(dst, src, size));
//        printf("dst: %s\n", dst);
//        return (0);
//}

// STRLCAT
//int     main(void)
//{
//	char	*dst;
//
//	if (!(dst = (char *)malloc(sizeof(*dst) * 15)))
//		return (0);
//	memset(dst, 0, 15);
//	memset(dst, 'r', 15);
//        char src[] = "lore; ipsum dolor sit amet";
//	printf("Resultats: dest: %s et retour: %zu\n", dst, strlcat(dst, src, 5));
//        return (0);
//}

// TOUPPER
//int   main(int argc, char **argv)
//{
//      printf("Officielle: %d\n", ft_toupper(*argv[1]));
//      return (0);
//}

// TOLOWER
//int   main(int argc, char **argv)
//{
//      printf("Officielle: %d\n", ft_tolower(*argv[1]));
//      return (0);
//}

// STRCHR
//int   main(void)
//{
//      char *s = "tripouille";
//	printf("Officielle: %s\n", strchr(s, 't' + 4*256));
//	printf("Bibi: %s\n", ft_strchr(s, 't' + 4*256));
//      return (0);
//}

// STRRCHR
//int   main(void)
//{
//      char    *s = "Pouet!";
//      char    c;
//
//      c = 'x';
//      printf("Officielle: %s\n", strrchr(s, c));
//      printf("Bibi: %s\n", ft_strrchr(s, c));
//      return (0);
//}

// STRNCMP
//int   main(void) 
//{ 
//      char    *s1; 
//      char    *s2; 
//      int     n; 
//       
//      s1 = "Tripouille"; 
//      s2 = "TripouilleX"; 
//      n = 42; 
//      printf("Officielle: %d\n", strncmp(s1, s2, n)); 
//      printf("Bibi: %d\n", ft_strncmp(s1, s2, n)); 
//      return (0); 
//} 

// MEMCHR
//int   main(void)
//{
//	char	*str;
//
//	str = "";
//      printf("%s\n", (char *)memchr(str, '\0', 0x20));
//      printf("%s\n", (char *)ft_memchr(str, '\0', 0x20));
//      return (0);
//}

// MEMCMP
//int   main(void)
//{
//      char    s1[] = "trf\200";
//      char    s2[] = "trf\0";
//      int     n;
//      
//      n = 4;
//      printf("Officielle: %d\n", memcmp(s2, s1, n));
//      printf("Bibi: %d\n", ft_memcmp(s2, s1, n));
//      return (0);
//}

// STRNSTR
//int   main(void)
//{
//      const char      *s1 = "aaabcabcd";
//      const char      *s2 = "cd";
//      int             len = 8;
//
//      printf("Officielle: %s\n", strnstr(s1, s2, len));
//      printf("Bibi: %s\n", ft_strnstr(s1, s2, len));
//      return (0);
//}
 
// ATOI
//int   main(void)
//{
//      char *s = "\t\n\v\f\r+1";
//      printf("Officielle: %d\n", atoi(s));
//      printf("Bibi: %d\n", ft_atoi(s));
//      return (0);
//}

// CALLOC
//int   main(void)
//{
//      char    *test;
//      int     n;
//
//      n = 5;
//      test = ft_calloc(n, sizeof(char));
//      memset(test, 97, n);
//      printf("resultat: %s\n", test);
//      return (0);
//}

// STRDUP
//int   main(void)
//{
//      char    str[] = "Pouet Bye";
//      char    *off;
//      char    *bibi;
//
//      off = strdup(str);
//      bibi = ft_strdup(str);
//      printf("Officielle: %s\n", off);
//      printf("Bibi: %s\n", bibi);
//      return (0);
//}

// SUBSTR
//int   main(void)
//{
//	char	*str = strdup("0123456789");
//	char	*s = ft_substr(str, 9, 10);
//	printf("%s\n", s);
//      return (0);
//}

// STRJOIN
//int   main(void)
//{
//      char    *s1 = "Salut ";
//      char    *s2 = "les Noobs!";
//
//      printf("Bibi: %s\n", ft_strjoin(s1, s2));
//      return (0);
//}

// STRTRIM
//int   main(void)
//{
//      char s[] = "abcdba";
//      char set[] = "acb";
//
//      printf("Resultat: %s\n", ft_strtrim(s, set));
//      return (0);
//}

// SPLIT
//int   main(void)
//{
//	char	splitme[] = "--1-2--3---4----5-----42";
//	char **tab = ft_split(splitme, '-');
//	int	i = 0;
//
//	printf("//////////////////////\n");
//	while (tab[i])
//	{
//		printf("%s\n", tab[i]);
//		i++;
//	}
//	printf("tab[6]: %s\n", tab[6]);
//	return (0);
//}

// ITOA
//int   main(void)
//{
//	srand(clock());
//	int	n;
//	char	*d;
//
//	for (int i = 0; i < 2000; i++)
//	{
//		n = rand();
//		d = ft_itoa(n);
//		if (atoi(d) != n)
//		{
//			printf("d: %s et n: %d\n", d, n);
//			return (0);
//		}
//	}
//	int	n = 1430876828;
//	char	*result;
//	
//	result = ft_itoa(n);
//	int i = 0;
//	while (result[i])
//	{
//		write(1, &result[i], 1);
//		i++;
//	}
//	return (0);
//}

// STRMAPI
//char  ft_test(unsigned int i, char c)
//{
//      if (i % 2 == 1)
//              c = 'Q';
//      return (c);
//}
//
//
//int   main(void)
//{
//      char    *s = "Pouet";
//
//      printf("Avant: %s\n", s);
//      printf("Apres: %s\n", ft_strmapi(s, &ft_test));
//      return (0);
//}

// STRITERI
//void  ft_test(unsigned int i, char *ptr)
//{
//      if (i % 2 == 1)
//              *ptr = 'X';
//}
//int   main(void)
//{
//      char    s[] = "Pouet";
//
//      ft_striteri(s, &ft_test);
//      printf("s apres: %s\n", s);
//      return (0);
//}

// PUTCHAR
//int     main()
//{
//        int     fd;
//
//        fd = open("42", O_WRONLY | O_CREAT, S_IRUSR | S_IWUSR);
//        if (fd == -1)
//                return (1);
//        ft_putchar_fd('X', fd);
//        ft_putchar_fd('Q', 1);
//        if (close(fd) == -1)
//                return (1);
//        return (0);
//}

// PUTENDL
//int     main()
//{
//        int     fd;
//        char    s[] = "Pouet pouet!";
//
//        fd = open("42", O_WRONLY | O_CREAT, S_IRUSR | S_IWUSR);
//        if (fd == -1)
//                return (1);
//        ft_putendl_fd(s, fd);
//        if (close(fd) == -1)  // Fermer le fichier
//                return (1);
//        return (0);
//}

// PUTNBR
//int   main()
//{ 
//      int     fd; 
//      int     nb = 10;
//      char	*result;
//
//	result = ft_itoa(nb);
//      printf("result itoa: %s\n", result);
//      fd = open("42", O_WRONLY | O_CREAT, S_IRUSR | S_IWUSR); 
//      if (fd == -1) 
//              return (1); 
//      ft_putnbr_fd(nb, fd); 
//      if (close(fd) == -1) 
//              return (1); 
//      return (0); 
//} 

//int	main(void)
//{
//	ft_putnbr_fd(-2147483648, 1);
//	return (0);
//}
