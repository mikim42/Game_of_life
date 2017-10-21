/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_of_life.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikim <mikim@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/20 16:59:14 by mikim             #+#    #+#             */
/*   Updated: 2017/10/21 12:08:23 by mikim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_OF_LIFE
# define GAME_OF_LIFE

# include <mlx.h>
# include <libft.h>

/*
Rule 1. Any live cell with fewer than two live neighbours dies,
		as if caused by underpopulation
Rule 2. Any live cell with two or three live neighbours
		lives on to the next generation
Rule 3. Any live cell with more than three live neighbours dies,
		as if by overpopulation.
Rule 4. Any dead cell with exactly three live neighbours becomes a live cell,
		as if by reproduction.
*/

typedef struct		s_slist
{
	char			**split;
	struct	s_slist	*next;
}					t_slist;

typedef struct		s_env
{
	t_slist			*slist;
	char			**life;
	char			**next;
}					t_env;

/*
**					parse
*/
void				parse_life(t_env *e);
void				parse_env(t_env *e);

/*
**					game_of_life
*/
void				next_generation(char **life1, char **life2);
void				game_of_life(t_env *e);

/*
**					handler
*/
void				print_life(char **life);
void				dead_cell(char **life, int y, int x, int cnt);
void				live_cell(char **life, int y, int x, int cnt);
int					count_life(char **life, int y, int x);
char				*store_split(t_slist *slist);
int					size_slist_x(t_slist *slist);
int					size_slist_y(t_slist **slist);
void				add_slist(t_slist **head, t_slist *elem);

#endif
