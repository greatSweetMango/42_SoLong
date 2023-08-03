/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehyuki <jaehyuki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/08 19:35:15 by jaehyuki          #+#    #+#             */
/*   Updated: 2022/08/08 19:35:16 by jaehyuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H

# include <stdio.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include "mlx.h"
# include "libft.h"
# include "get_next_line.h"

# define IMG 64
# define KEY_UP 13
# define KEY_DOWN 1
# define KEY_LEFT 0
# define KEY_RIGHT 2
# define KEY_ESC 53
# define DEAD 1
# define CLEAR 2

typedef struct s_pos
{
	int	x;
	int	y;
}	t_pos;

typedef struct s_player
{
	t_pos	pos;
	t_pos	pre_pos;
	void	*img;
	void	*img2;
	void	*dead_img;
}	t_player;

typedef struct s_enemy
{
	t_pos	pos;
	t_pos	pre_pos;
	void	*img;
}	t_enemy;

typedef struct s_game
{
	void		*mlx;
	void		*win;
	t_pos		map_size;
	t_pos		door_pos;
	char		**map;
	void		*tile_img;
	void		*door_img;
	void		*wall_img;
	void		*item_img;
	void		*clear_img;
	void		*black_img;
	t_player	player;
	t_enemy		enemy;
	int			items;
	int			moves;
	int			state;
}	t_game;

int		init_game(t_game *game, int argc, char **argv);
void	parse_map(t_game *game, char *file);
int		push_keys(int keycode, t_game *game);
int		update(t_game *game);
void	draw_screen(t_game *game);
void	draw_clear_screen(t_game *game);
void	param_check(int argc);
void	task_alloc_error(t_game *game, int i);
void	task_file_open_error(void);
void	task_map_error(t_game *game);
void	map_check(t_game *game);
void	task_move_random(t_game *game, t_pos pos, int random, int *flag);
#endif
