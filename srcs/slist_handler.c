/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   slist_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikim <mikim@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/20 17:40:14 by mikim             #+#    #+#             */
/*   Updated: 2017/10/20 20:49:04 by mikim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <game_of_life.h>

char	*store_split(t_slist *slist)
{
	char	*life;
	int		i;

	i = -1;
	while (slist->split[++i])
		;
	life = ft_memalloc(sizeof(char) * (i + 1));
	i = -1;
	while (slist->split[++i])
		life[i] = slist->split[i][0];
	return (life);
}

int		size_slist_x(t_slist *slist)
{
	int x;

	x = -1;
	while (slist->split[++x])
		;
	return (x);
}

int		size_slist_y(t_slist **head)
{
	t_slist *tmp;
	int		y;

	y = 0;
	tmp = *head;
	while (tmp)
	{
		++y;
		tmp = tmp->next;
	}
	return (y);
}

void	add_slist(t_slist **head, t_slist *elem)
{
	t_slist *tmp;

	tmp = *head;
	if (!tmp)
		*head = elem;
	else
		while (tmp && tmp != elem)
		{
			if (!tmp->next)
				tmp->next = elem;
			tmp = tmp->next;
		}
}

