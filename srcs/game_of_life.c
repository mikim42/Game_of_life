/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_of_life.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikim <mikim@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/20 19:16:25 by mikim             #+#    #+#             */
/*   Updated: 2017/10/21 12:12:45 by mikim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <game_of_life.h>

void	next_generation(char **life1, char **life2)
{
	int y;
	int x;
	int cnt;
	
	y = -1;
	while (life1[++y])
	{
		x = -1;
		while (life1[y][++x])
		{
			cnt = count_life(life1, y, x);
			if (life1[y][x] == '1')
				live_cell(life2, y, x, cnt);
			else
				dead_cell(life2, y, x, cnt);
		}
	}
}

void	game_of_life(t_env *e)
{
	int flag;

	flag = 0;
	while (1)
	{
		flag == 0 ? print_life(e->life) : print_life(e->next);
		flag == 0 ?
		next_generation(e->life, e->next) : next_generation(e->next, e->life);
		usleep(200000);
		flag = (flag == 0 ? 1 : 0);
		ft_printf("\n");
	}
}
