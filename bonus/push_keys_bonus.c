/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_keys_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehyuki <jaehyuki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/12 19:51:38 by jaehyuki          #+#    #+#             */
/*   Updated: 2022/08/12 19:51:39 by jaehyuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	move_check(t_game *game)
{
	if ((game->enemy.pos.x == game->player.pos.x
			&& game->enemy.pos.y == game->player.pos.y)
		|| (game->enemy.pre_pos.x == game->player.pos.x
			&& game->enemy.pre_pos.y == game->player.pos.y
			&& game->enemy.pos.x == game->player.pre_pos.x
			&& game->enemy.pos.y == game->player.pre_pos.y))
			game->state = DEAD;
	if (game->map[game->player.pos.x][game->player.pos.y] == '1'
		|| (game->map[game->player.pos.x][game->player.pos.y] == 'E'
		&& game->items > 0))
		game->player.pos = game->player.pre_pos;
	else
	{
		game->moves++;
		printf("moves: [ %d ]\n", game->moves);
	}
	return (0);
}

void	update_game(t_game *game)
{
	int	img_width;
	int	img_height;

	if (game->map[game->player.pos.x][game->player.pos.y] == 'C')
	{
		game->map[game->player.pos.x][game->player.pos.y] = '0';
		game->items--;
	}
	if (game->items <= 0)
		game->door_img = mlx_xpm_file_to_image(game->mlx,
				"./sprites/house_open.xpm", &img_width, &img_height);
	if (game->map[game->player.pos.x][game->player.pos.y] == 'E'
		&& game->items <= 0)
		game->state = CLEAR;
}

void	move_random(t_game *game, t_pos pos, int random, int random_temp)
{
	int	flag;

	flag = 0;
	while (random_temp != random)
	{
		if (random > 3)
			random = 0;
		task_move_random(game, pos, random, &flag);
		if (flag)
			break ;
		random++;
	}
}

void	move_enemy(t_game *game)
{
	int	random;
	int	random_temp;

	if (game->enemy.pos.x == 0 || game->enemy.pos.y == 0)
		return ;
	random = 0;
	random = (game->player.pos.x + game->player.pos.y
			+ game->moves + game->items + game->enemy.pos.x
			+ game->enemy.pos.y) % INT_MAX;
	random_temp = (random - 1) % 4;
	random = random % 4;
	game->enemy.pre_pos = game->enemy.pos;
	if (game->map[game->enemy.pos.x + 1][game->enemy.pos.y] == '0'
		|| game->map[game->enemy.pos.x - 1][game->enemy.pos.y] == '0'
		|| game->map[game->enemy.pos.x][game->enemy.pos.y + 1] == '0'
		|| game->map[game->enemy.pos.x][game->enemy.pos.y - 1] == '0')
		move_random(game, game->enemy.pos, random, random_temp);
}

int	push_keys(int keycode, t_game *game)
{
	if (game->state || (keycode != KEY_UP && keycode != KEY_DOWN
			&& keycode != KEY_LEFT && keycode != KEY_RIGHT))
	{	
		if (keycode == KEY_ESC)
			exit(0);
		return (0);
	}
	game->player.pre_pos = game->player.pos;
	if (keycode == KEY_UP)
		game->player.pos.x--;
	else if (keycode == KEY_DOWN)
		game->player.pos.x++;
	else if (keycode == KEY_LEFT)
		game->player.pos.y--;
	else if (keycode == KEY_RIGHT)
		game->player.pos.y++;
	else if (keycode == KEY_ESC)
		exit(0);
	move_enemy(game);
	move_check(game);
	update_game(game);
	return (0);
}
