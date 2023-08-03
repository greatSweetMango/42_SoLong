/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehyuki <jaehyuki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/10 23:21:37 by jaehyuki          #+#    #+#             */
/*   Updated: 2022/08/10 23:21:39 by jaehyuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	get_map_size_x(t_game *game, char *file)
{
	int		fd;
	int		flag;
	char	*line;

	flag = 1;
	game->map_size.x = 0;
	fd = open(file, O_RDONLY);
	if (fd < 0)
		task_file_open_error();
	while (flag)
	{
		line = get_next_line(fd);
		if (!line)
			flag = 0;
		else
		{
			free(line);
			game->map_size.x++;
		}
	}
	close(fd);
	return (1);
}

int	alloc_map(t_game *game, char *file)
{
	int	fd;
	int	i;
	int	flag;

	flag = 1;
	fd = open(file, O_RDONLY);
	if (fd < 0)
		task_file_open_error();
	game->map = (char **)malloc((game->map_size.x + 1) * sizeof(char *));
	if (!game->map)
		task_alloc_error(game, -1);
	i = 0;
	while (i < game->map_size.x)
	{
		game->map[i] = get_next_line(fd);
		if (!game->map[i])
			task_alloc_error(game, i);
		i++;
	}
	game->map_size.y = ft_strlen(game->map[i - 1]);
	game->map[i] = NULL;
	close(fd);
	return (1);
}

void	parse_map(t_game *game, char *file)
{
	get_map_size_x(game, file);
	alloc_map(game, file);
	map_check(game);
}
