/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikim <mikim@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/20 19:16:51 by mikim             #+#    #+#             */
/*   Updated: 2017/10/21 12:01:10 by mikim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <game_of_life.h>

void	print_life(char **life)
{
	int	i;
	int j;

	i = -1;
	system("clear");
	while (life[++i])
	{
		j = -1;
		while (life[i][++j])
		{
			if (life[i][j] == '1')
			{
				write(1, "\x1b[44m", 5);
				write(1, &life[i][j], 1);
			}
			else
			{
				write(1, "\x1b[41m", 5);
				write(1, &life[i][j], 1);
			}
		}
		write(1, "\x1b[0m\n", 6);
	}
}
