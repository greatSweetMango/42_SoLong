/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehyuki <jaehyuki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/13 20:23:24 by jaehyuki          #+#    #+#             */
/*   Updated: 2022/08/13 20:23:26 by jaehyuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	wall_check(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (i < game->map_size.x)
	{
		j = 0;
		while (j < game->map_size.y)
		{
			if ((i == 0 || i == game->map_size.x - 1
					|| j == 0 || j == game->map_size.y - 1)
				&& game->map[i][j] != '1')
			{
				printf("(Wall is wrong)\n");
				task_map_error(game);
			}
			j++;
		}
		i++;
	}
}

void	elements_check(t_game *game)
{
	int	door;
	int	player;
	int	i;
	int	j;
	int	item;

	door = 0;
	player = 0;
	item = 0;
	i = -1;
	while (i++ < game->map_size.x - 1)
	{
		j = -1;
		while (j++ < game->map_size.y - 1)
		{
			if (game->map[i][j] == 'E')
				door++;
			else if (game->map[i][j] == 'P')
				player++;
			else if (game->map[i][j] == 'C')
				item++;
		}
	}
	if (!door || !player || !item)
		task_map_error(game);
}

void	elements_vaildcheck(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (i < game->map_size.x)
	{
		j = 0;
		while (j < game->map_size.y)
		{
			if (game->map[i][j] != '0' && game->map[i][j] != '1'
				&& game->map[i][j] != 'C' && game->map[i][j] != 'E'
				&& game->map[i][j] != 'P')
				task_map_error(game);
			j++;
		}
		i++;
	}
}

void	rectangle_check(t_game *game)
{
	int	i;

	if ((game->map_size.x - 2) * (game->map_size.y - 2) < 4
		&& game->map_size.x < 3 && game->map_size.y < 3)
		task_map_error(game);
	i = 0;
	while (i < game->map_size.x)
	{
		if (ft_strlen(game->map[i]) != (size_t)game->map_size.y)
			task_map_error(game);
		i++;
	}
}

void	map_check(t_game *game)
{
	wall_check(game);
	elements_check(game);
	elements_vaildcheck(game);
	rectangle_check(game);
}
