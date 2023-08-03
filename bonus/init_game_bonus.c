/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehyuki <jaehyuki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/10 23:42:17 by jaehyuki          #+#    #+#             */
/*   Updated: 2022/08/16 16:56:28 by jaehyuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	set_imgs(t_game *game)
{
	int	img_width;
	int	img_height;

	game->player.img = mlx_xpm_file_to_image(game->mlx,
			"./sprites/cat.xpm", &img_width, &img_height);
	game->player.img2 = mlx_xpm_file_to_image(game->mlx,
			"./sprites/cat2.xpm", &img_width, &img_height);
	game->player.dead_img = mlx_xpm_file_to_image(game->mlx,
			"./sprites/cat_dead.xpm", &img_width, &img_height);
	game->enemy.img = mlx_xpm_file_to_image(game->mlx,
			"./sprites/dog.xpm", &img_width, &img_height);
	game->tile_img = mlx_xpm_file_to_image(game->mlx,
			"./sprites/tile.xpm", &img_width, &img_height);
	game->door_img = mlx_xpm_file_to_image(game->mlx,
			"./sprites/house.xpm", &img_width, &img_height);
	game->wall_img = mlx_xpm_file_to_image(game->mlx,
			"./sprites/rock.xpm", &img_width, &img_height);
	game->item_img = mlx_xpm_file_to_image(game->mlx,
			"./sprites/fish.xpm", &img_width, &img_height);
	game->clear_img = mlx_xpm_file_to_image(game->mlx,
			"./sprites/green_pannel.xpm", &img_width, &img_height);
	game->black_img = mlx_xpm_file_to_image(game->mlx,
			"./sprites/black_pannel.xpm", &img_width, &img_height);
}

void	set_elements(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (game->map[i])
	{
		j = 0;
		while (game->map[i][j])
		{
			if (game->map[i][j] == 'E')
			{
				game->door_pos.x = i;
				game->door_pos.y = j;
			}
			else if (game->map[i][j] == 'P')
			{
				game->player.pos.x = i;
				game->player.pos.y = j;
			}
			else if (game->map[i][j] == 'C')
				game->items++;
			j++;
		}
		i++;
	}
}

void	init_enemy_pos(t_game *game, t_pos end_pos)
{
	if (game->enemy.pos.x == end_pos.x && game->enemy.pos.y == end_pos.y)
	{
		game->enemy.pos.x = 0;
		game->enemy.pos.y = 0;
	}
}

void	put_enemy(t_game *game)
{
	t_pos	end_pos;

	game->enemy.pos.x = ((game->player.pos.x + game->player.pos.y
				+ game->map_size.x + game->map_size.y) * 3) % (INT_MAX - 1);
	game->enemy.pos.y = game->enemy.pos.x % game->map_size.y;
	game->enemy.pos.x = game->enemy.pos.x % game->map_size.x;
	end_pos = game->enemy.pos;
	game->enemy.pos.y++;
	while (game->enemy.pos.x != end_pos.x || game->enemy.pos.y != end_pos.y)
	{
		if (game->map[game->enemy.pos.x][game->enemy.pos.y] == '0')
			break ;
		if (game->enemy.pos.y >= game->map_size.y)
		{
			game->enemy.pos.x++;
			game->enemy.pos.y = -1;
		}
		if (game->enemy.pos.x >= game->map_size.x)
			game->enemy.pos.x = 0;
		game->enemy.pos.y++;
	}
	init_enemy_pos(game, end_pos);
}

int	init_game(t_game *game, int argc, char **argv)
{
	param_check(argc);
	game->items = 0;
	game->moves = 0;
	game->state = 0;
	parse_map(game, argv[1]);
	set_elements(game);
	put_enemy(game);
	game->mlx = mlx_init();
	game->win = mlx_new_window(game->mlx,
			game->map_size.y * IMG + 64,
			game->map_size.x * IMG,
			"so_long");
	set_imgs(game);
	draw_screen(game);
	return (1);
}
