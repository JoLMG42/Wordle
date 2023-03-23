/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_lst.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdefonte <cdefonte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/10 20:00:55 by cdefonte          #+#    #+#             */
/*   Updated: 2022/05/14 19:16:26 by cdefonte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wordle.h"

t_c	*ft_new_try(char *str, int *colors)
{
	t_c	*new_token;

	new_token = malloc(sizeof(t_c));
	if (!new_token)
		return (NULL);
	new_token->strtry = str;
	if (!colors)
	{
		new_token->colors = calloc(6, sizeof(int));
		if (!new_token->colors)
			return (free(new_token->strtry), free(new_token), NULL);
	}
	else
		new_token->colors = colors;
	new_token->next = NULL;
	return (new_token);
}

t_c	*ft_tokenlst_last(t_c *lst)
{
	if (lst == NULL)
		return (NULL);
	while (lst->next != NULL)
		lst = lst->next;
	return (lst);
}

void	try_addback(t_c **alst, t_c *new)
{
	t_c	*last;

	if (alst == NULL || new == NULL)
		return ;
	if (*alst == NULL)
	{
		*alst = new;
		return ;
	}
	last = ft_tokenlst_last(*alst);
	last->next = new;
}

void	try_lst_free(t_c *lst)
{
	t_c	*prev;

	while (lst)
	{
		prev = lst;
		lst = lst->next;
		free(prev->strtry);
		prev->strtry = NULL;
		free(prev->colors);
		prev->colors = NULL;
		free(prev);
		prev = NULL;
	}
}
