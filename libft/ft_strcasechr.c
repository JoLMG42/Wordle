/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcasechr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdefonte <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 10:14:24 by cdefonte          #+#    #+#             */
/*   Updated: 2022/05/15 13:50:40 by cdefonte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h" 
#include <stdio.h>

static int	is_chrcasecmp(char c1, char c2)
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

char	*ft_strcasechr(const char *s, int c)
{
	char	*ptr;
	int		i;

	i = 0;
	ptr = (char *)s;
	while (s[i])
	{
		if (is_chrcasecmp(s[i], c))
			return (ptr + i);
		i++;
	}
	if (c == '\0')
		return (ptr + i);
	return (NULL);
}
