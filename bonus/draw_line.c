/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nouahidi <nouahidi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 22:31:03 by lsabik            #+#    #+#             */
/*   Updated: 2023/07/28 12:44:07 by nouahidi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/cub3d.h"

void	drawline_norm(t_cub3d_data *cub, int x2, int y2)
{
	int	x1;
	int	y1;
	int	err;
	int	err2;

	x1 = (MP_WIDTH / 2);
	y1 = (MP_HEIGHT / 2);
	err = cub->dx - cub->dy;
	while (x1 != x2 || y1 != y2)
	{
		mlx_put_pixel(cub->minimap, x1, y1, WHITE_MP);
		err2 = 2 * err;
		if (err2 > -cub->dy)
		{
			err -= cub->dy;
			x1 += cub->sx;
		}
		if (err2 < cub->dx)
		{
			err += cub->dx;
			y1 += cub->sy;
		}
	}
}

void	drawline(t_cub3d_data *cub, int x2, int y2)
{
	int	x1;
	int	y1;

	x1 = (MP_WIDTH / 2);
	y1 = (MP_HEIGHT / 2);
	cub->dx = abs(x2 - x1);
	cub->dy = abs(y2 - y1);
	if (x1 < x2)
		cub->sx = 1;
	else
		cub->sx = -1;
	if (y1 < y2)
		cub->sy = 1;
	else
		cub->sy = -1;
	drawline_norm(cub, x2, y2);
}
