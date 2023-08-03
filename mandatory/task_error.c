/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   task_error.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehyuki <jaehyuki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/13 18:24:05 by jaehyuki          #+#    #+#             */
/*   Updated: 2022/08/13 18:24:06 by jaehyuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	param_check(int argc)
{
	if (argc != 2)
	{
		printf("Error\nPlease put 1 parameter");
		exit(1);
	}
}

void	task_alloc_error(t_game *game, int i)
{
	while (i-- > 0)
		free(game->map[i]);
	free(game->map);
	printf("Error\nAlloc fail!!\n");
	exit(1);
}

void	task_file_open_error(void)
{
	printf("Error\nMap file is not exist!!\n");
	exit(1);
}

void	task_map_error(t_game *game)
{
	int	i;

	i = game->map_size.x;
	while (i-- > 0)
		free(game->map[i]);
	free(game->map);
	printf("Error\nMap is not available!!\n");
	exit(1);
}
