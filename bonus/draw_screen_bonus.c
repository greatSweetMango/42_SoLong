/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_screen_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehyuki <jaehyuki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/13 15:16:49 by jaehyuki          #+#    #+#             */
/*   Updated: 2022/08/13 15:16:50 by jaehyuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	draw_player(t_game *game)
{
	static int	frame_rate = 0;

	if (game->state == DEAD)
		mlx_put_image_to_window(game->mlx, game->win, game->player.dead_img,
			IMG * game->player.pos.y, IMG * game->player.pos.x);
	else
	{
		if (frame_rate < 100)
			mlx_put_image_to_window(game->mlx, game->win, game->player.img,
				IMG * game->player.pos.y, IMG * game->player.pos.x);
		else if (frame_rate >= 100)
		{
			mlx_put_image_to_window(game->mlx, game->win, game->player.img2,
				IMG * game->player.pos.y, IMG * game->player.pos.x);
			if (frame_rate >= 200)
				frame_rate = 0;
		}
	}
	frame_rate++;
}

void	draw_enenmy(t_game *game)
{
	if (game->state == DEAD)
		mlx_put_image_to_window(game->mlx, game->win, game->tile_img,
			IMG * game->enemy.pos.y, IMG * game->enemy.pos.x);
	else if (game->map[game->enemy.pos.x][game->enemy.pos.y] == '0')
		mlx_put_image_to_window(game->mlx, game->win, game->enemy.img,
			IMG * game->enemy.pos.y, IMG * game->enemy.pos.x);
}

void	draw_map(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (game->map[i])
	{
		j = 0;
		while (game->map[i][j])
		{
			mlx_put_image_to_window(game->mlx, game->win, game->tile_img,
				IMG * j, IMG * i);
			if (game->map[i][j] == '1')
				mlx_put_image_to_window(game->mlx, game->win,
					game->wall_img, IMG * j, IMG * i);
			else if (game->map[i][j] == 'C')
				mlx_put_image_to_window(game->mlx, game->win, game->item_img,
					IMG * j, IMG * i);
			else if (game->map[i][j] == 'E')
				mlx_put_image_to_window(game->mlx, game->win, game->door_img,
					IMG * j, IMG * i);
			j++;
		}
		i++;
	}
}

void	draw_movecount(t_game *game)
{
	char	*str;

	str = ft_itoa(game->moves);
	if (!str)
		exit(1);
	mlx_put_image_to_window(game->mlx, game->win, game->black_img,
		IMG * (game->map_size.y), 0);
	mlx_string_put (game->mlx, game->win, IMG * game->map_size.y + (IMG / 2),
		game->map_size.x + (IMG / 2), 0xFFFFFF, str);
	free(str);
}

void	draw_screen(t_game *game)
{
	draw_map(game);
	draw_enenmy(game);
	draw_player(game);
	draw_movecount(game);
}
