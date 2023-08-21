/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fullmaputils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nouahidi <nouahidi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 09:34:44 by nouahidi          #+#    #+#             */
/*   Updated: 2023/07/27 00:24:35 by nouahidi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	puts_walls(int x, int y, t_cub3d_data *cub, int flag)
{
	int	tmpx;
	int	tmpy;

	tmpx = x;
	tmpy = y;
	while (y < tmpy + cub->y_wall - 1)
	{
		x = tmpx;
		while (x < tmpx + cub->x_wall - 1)
		{
			if (flag == 1)
				mlx_put_pixel(cub->full_map, x++, y, WHITE_MP);
			else if (flag == 2)
				mlx_put_pixel(cub->full_map, x++, y, 0xA9A9A9FF);
			else if (flag == 3)
				mlx_put_pixel(cub->full_map, x++, y, GREEN_MP);
			else if (flag == 4)
				mlx_put_pixel(cub->full_map, x++, y, DARKGREY_MP);
			else
				mlx_put_pixel(cub->full_map, x++, y, PURPLE_MP);
		}
		y++;
	}
}

void	draw_fullmap_cont(t_cub3d_data *cub, int j, int x, int y)
{
	if (cub->matrice[j][cub->tmp_vl] == '1')
		puts_walls(x, y, cub, 1);
	else if (cub->matrice[j][cub->tmp_vl] == 'D')
		puts_walls(x, y, cub, 2);
	else if (cub->matrice[j][cub->tmp_vl] == 'Y')
		puts_walls(x, y, cub, 5);
	else if (cub->matrice[j][cub->tmp_vl] == 'T')
		puts_walls(x, y, cub, 3);
	else if (cub->matrice[j][cub->tmp_vl] == 'y')
		puts_walls(x, y, cub, 0);
	else if (cub->matrice[j][cub->tmp_vl] == 'L')
		puts_walls(x, y, cub, 4);
}

void	draw_fullmap(t_cub3d_data *cub)
{
	int			x;
	int			y;
	int			i;
	int			j;

	i = 0;
	j = -1;
	y = cub->beginy;
	while (cub->matrice[++j])
	{
		i = 0;
		x = cub->beginx;
		while (cub->matrice[j][i])
		{
			cub->tmp_vl = i;
			draw_fullmap_cont(cub, j, x, y);
			i++;
			x += cub->x_wall;
		}
		y += cub->y_wall;
	}
}
