/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rule_handler.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikim <mikim@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/20 20:05:47 by mikim             #+#    #+#             */
/*   Updated: 2017/10/20 20:40:26 by mikim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <game_of_life.h>

void	dead_cell(char **life, int y, int x, int cnt)
{
	if (cnt == 3)
		life[y][x] = '1';
	else
		life[y][x] = '0';
}

void	live_cell(char **life, int y, int x, int cnt)
{
	if (cnt == 2 || cnt == 3)
		life[y][x] = '1';
	else
		life[y][x] = '0';
}

int		count_life(char **life, int y, int x)
{
	int cnt;

	cnt = 0;
	cnt += (y > 0 && x > 0 && life[y - 1][x - 1] == '1' ? 1 : 0);
	cnt += (y > 0 && life[y - 1][x] == '1' ? 1 : 0);
	cnt += (y > 0 && life[y - 1][x + 1] == '1' ? 1 : 0);
	cnt += (x > 0 && life[y][x - 1] == '1' ? 1 : 0);
	cnt += (life[y][x + 1] == '1' ? 1 : 0);
	cnt += (life[y + 1] && life[y + 1][x - 1] == '1' ? 1 : 0);
	cnt += (life[y + 1] && life[y + 1][x] == '1' ? 1 : 0);
	cnt += (life[y + 1] && life[y + 1][x + 1] == '1' ? 1 : 0);
	return (cnt);
}
