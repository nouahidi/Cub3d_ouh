/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fullmap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsabik <lsabik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 09:28:39 by nouahidi          #+#    #+#             */
/*   Updated: 2023/07/24 14:56:03 by lsabik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	puts_player(t_cub3d_data *cub)
{
	int	x;
	int	y;

	y = cub->player->mpy - (cub->y_wall / 3) - 1;
	while (++y < cub->player->mpy + (cub->y_wall / 3))
	{
		x = cub->player->mpx - (cub->y_wall / 3);
		while (x < cub->player->mpx + (cub->x_wall / 3))
		{
			if (distance(cub->player->mpx, \
			cub->player->mpy, x, y) < (cub->y_wall / 3))
				mlx_put_pixel(cub->full_map, x, y, BLACK_MP);
			x++;
		}
	}
}

void	background_fullmap(t_cub3d_data *cub)
{
	int	x;
	int	y;

	y = -1;
	while (++y < HEIGHT_FULLMAP)
	{
		x = 0;
		while (x < WIDTH_FULLMAP)
			mlx_put_pixel(cub->full_map, x++, y, get_color(191, 191, 191, 150));
	}
}

void	framing_norm(t_cub3d_data *cub)
{
	int			x;
	int			y;

	y = HEIGHT_FULLMAP - 6;
	while (++y < HEIGHT_FULLMAP)
	{
		x = 0;
		while (x < WIDTH_FULLMAP)
			mlx_put_pixel(cub->full_map, x++, y, BLACK_MP);
	}
	y = -1;
	while (++y < HEIGHT_FULLMAP)
	{
		x = WIDTH_FULLMAP - 5;
		while (x < WIDTH_FULLMAP)
			mlx_put_pixel(cub->full_map, x++, y, BLACK_MP);
	}
}

void	framing_fullmap(t_cub3d_data *cub)
{
	int			x;
	int			y;

	y = -1;
	while (++y < 5)
	{
		x = 0;
		while (x < WIDTH_FULLMAP)
			mlx_put_pixel(cub->full_map, x++, y, BLACK_MP);
	}
	y = -1;
	while (++y < HEIGHT_FULLMAP)
	{
		x = 0;
		while (x < 5)
			mlx_put_pixel(cub->full_map, x++, y, BLACK_MP);
	}
	framing_norm(cub);
}

void	setting_map(t_cub3d_data *cub)
{
	background_fullmap(cub);
	framing_fullmap(cub);
	cub->y_wall = HEIGHT_FULLMAP / cub->len_j;
	cub->x_wall = WIDTH_FULLMAP / cub->len_i;
	if (cub->y_wall < cub->x_wall)
		cub->x_wall = cub->y_wall;
	else
		cub->y_wall = cub->x_wall;
	cub->beginx = (WIDTH_FULLMAP / 2) - ((cub->len_i * cub->x_wall) / 2);
	cub->beginy = (HEIGHT_FULLMAP / 2) - ((cub->len_j * cub->y_wall) / 2);
	draw_fullmap(cub);
	cub->player->mpx = ((cub->player->x / W_DM) \
	* cub->x_wall) + cub->beginx;
	cub->player->mpy = ((cub->player->y / W_DM) \
	* cub->y_wall) + cub->beginy;
	puts_player(cub);
}
