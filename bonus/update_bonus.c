/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_screen_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehyuki <jaehyuki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/12 21:03:53 by jaehyuki          #+#    #+#             */
/*   Updated: 2022/08/12 21:03:55 by jaehyuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	update(t_game *game)
{
	if (game->state != CLEAR)
		draw_screen(game);
	else
		draw_clear_screen(game);
	return (1);
}
