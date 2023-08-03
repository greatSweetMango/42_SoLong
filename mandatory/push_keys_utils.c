/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_keys_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehyuki <jaehyuki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 17:13:42 by jaehyuki          #+#    #+#             */
/*   Updated: 2022/08/16 17:13:44 by jaehyuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	task_move_random(t_game *game, t_pos pos, int random, int *flag)
{
	if (random == 0 && game->map[pos.x + 1][pos.y] == '0')
	{
		game->enemy.pos.x++;
		*flag = 1;
	}
	else if (random == 1 && game->map[pos.x - 1][pos.y] == '0')
	{
		game->enemy.pos.x--;
		*flag = 1;
	}
	else if (random == 2 && game->map[pos.x][pos.y + 1] == '0')
	{
		game->enemy.pos.y++;
		*flag = 1;
	}
	else if (random == 3 && game->map[pos.x][pos.y - 1] == '0')
	{
		game->enemy.pos.y--;
		*flag = 1;
	}
	return ;
}
