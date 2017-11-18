/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikim <mikim@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/20 17:04:55 by mikim             #+#    #+#             */
/*   Updated: 2017/10/21 12:04:13 by mikim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <game_of_life.h>

void	parse_life(t_env *e)
{
	t_slist	*tmp;
	int		y;
	int		x;
	int		i;

	tmp = e->slist;
	y = size_slist_y(&e->slist);
	x = size_slist_x(e->slist);
	e->life = ft_memalloc(sizeof(char*) * (y + 1));
	e->next = ft_memalloc(sizeof(char*) * (y + 1));
	i = -1;
	while (++i < y)
	{
		e->life[i] = ft_memalloc(sizeof(char) * (x + 1));
		e->next[i] = ft_memalloc(sizeof(char) * (x + 1));
		e->life[i] = store_split(tmp);
		tmp = tmp->next;
	}
}

void	parse_env(t_env *e)
{
	t_slist	*slist;
	char	*line;

	while (get_next_line(0, &line) > 0)
	{
		slist = ft_memalloc(sizeof(slist));
		slist->split = ft_strsplit(line, ' ');
		slist->next = NULL;
		add_slist(&e->slist, slist);
		free(line);
	}
	parse_life(e);
}
