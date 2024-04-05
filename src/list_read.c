/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_read.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aduvilla <aduvilla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 14:13:19 by aduvilla          #+#    #+#             */
/*   Updated: 2024/03/14 16:07:11 by aduvilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_read_listclear(t_read **list)
{
	t_read	*buf;

	if (*list)
	{
		while ((*list)->next)
		{
			buf = (*list)->next;
			free((*list)->read);
			free(*list);
			*list = buf;
		}
		free((*list)->read);
		free(*list);
		*list = NULL;
	}
}

t_read	*ft_read_listnew(char *str)
{
	t_read	*new;

	new = malloc(sizeof(t_read) * 1);
	if (!new)
		return (NULL);
	new->read = str;
	if (!new->read)
		return (free(new), NULL);
	new->next = NULL;
	return (new);
}

t_read	*ft_read_listlast(t_read *list)
{
	if (!list)
		return (NULL);
	while (list->next != NULL)
		list = list->next;
	return (list);
}

void	ft_read_listadd_back(t_read **list, t_read *new)
{
	t_read	*buf;

	if (!list || !new)
		return ;
	if (*list == NULL)
		*list = new;
	else
	{
		buf = ft_read_listlast(*(list));
		buf->next = new;
	}
}

void	print_read_lst(t_read *list)
{
	int			i;
	t_read		*buf;

	i = 0;
	buf = list;
	if (buf)
	{
		while (buf)
		{
			ft_printf("read[%d] = %s\n", i, buf->read);
			buf = buf->next;
			i++;
		}
	}
}
