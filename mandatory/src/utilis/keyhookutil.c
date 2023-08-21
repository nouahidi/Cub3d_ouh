/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyhookutil.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nouahidi <nouahidi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 10:31:10 by nouahidi          #+#    #+#             */
/*   Updated: 2023/07/26 23:50:08 by nouahidi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	ft_tur_direction(t_cub3d_data *cub)
{
	double	turn_dir;

	if (mlx_is_key_down(cub->mlx, MLX_KEY_LEFT))
	{
		turn_dir = -1;
		cub->player_data->rot_angle += (turn_dir * ROT_SPEED);
	}
	if (mlx_is_key_down(cub->mlx, MLX_KEY_RIGHT))
	{
		turn_dir = 1;
		cub->player_data->rot_angle += (turn_dir * ROT_SPEED);
	}
}

int	wall_collision(t_cub3d_data *cub, double new_x, double new_y)
{
	int	px;
	int	py;

	px = (int)cub->player_data->x / WALL_DIMENSION;
	py = (int)cub->player_data->y / WALL_DIMENSION;
	if (cub->matrice[py][px] == '1')
		return (1);
	if (cub->matrice[py][(int)new_x] == '1' && cub->matrice[(int)new_y][px] \
	== '1')
		return (1);
	return (0);
}

void	walk_direction(t_cub3d_data *cub, int flag)
{
	double			walk_dir;
	double			px;
	double			py;
	double			mv_step;

	px = cub->player_data->x;
	py = cub->player_data->y;
	walk_dir = flag;
	mv_step = walk_dir * MV_SPEED;
	cub->player_data->x += cos(cub->player_data->rot_angle) * mv_step;
	cub->player_data->y += sin(cub->player_data->rot_angle) * mv_step;
	if (wall_collision(cub, (px / WALL_DIMENSION), (py / WALL_DIMENSION)))
	{
		cub->player_data->x = px;
		cub->player_data->y = py;
	}
}

void	side_direction(t_cub3d_data *cub, int flag)
{
	double			side_dir;
	double			px;
	double			py;
	double			mv_step;

	px = cub->player_data->x;
	py = cub->player_data->y;
	side_dir = flag;
	mv_step = side_dir * MV_SPEED;
	cub->player_data->x += cos(cub->player_data->rot_angle + \
	(M_PI / 2)) * mv_step;
	cub->player_data->y += sin(cub->player_data->rot_angle + \
	(M_PI / 2)) * mv_step;
	if (wall_collision(cub, (px / WALL_DIMENSION), (py / WALL_DIMENSION)))
	{
		cub->player_data->x = px;
		cub->player_data->y = py;
	}
}
