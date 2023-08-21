/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nouahidi <nouahidi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 14:47:32 by lsabik            #+#    #+#             */
/*   Updated: 2023/07/28 14:57:24 by nouahidi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

double	normalizeangle(double ray_ang)
{
	ray_ang = fmod(ray_ang, (2 * M_PI));
	if (ray_ang < 0)
		ray_ang = (2 * M_PI) + ray_ang;
	return (ray_ang);
}

void	init_ray_data(t_cub3d_data *cub)
{
	cub->rays = ft_calloc(1, sizeof(t_ray_data));
	cub->rays->ray_ang = cub->player_data->rot_angle;
	cub->rays->is_rayfacingdown = 0;
	cub->rays->is_rayfacingright = 0;
	cub->rays->is_rayfacingup = 0;
	cub->rays->is_rayfacingleft = 0;
}

void	ft_mlx_init(t_cub3d_data *cub)
{
	cub->mlx = mlx_init(WIDTH, HEIGHT, "MyCub3D", false);
	if (!cub->mlx)
	{
		puts(mlx_strerror(mlx_errno));
		exit(EXIT_FAILURE);
	}
	init_data_player(cub);
	init_ray_data(cub);
}

void	init_data_player(t_cub3d_data *cub)
{
	cub->player_data = ft_calloc(1, sizeof(t_data_player));
	if (cub->matrice[cub->player_y][cub->player_x])
	{
		cub->player_data->x = cub->player_x * WALL_DIMENSION + 16;
		cub->player_data->y = cub->player_y * WALL_DIMENSION + 16;
		if (cub->player_dir == 'E')
			cub->player_data->rot_angle = M_PI;
		if (cub->player_dir == 'N')
			cub->player_data->rot_angle = M_PI / 2;
		if (cub->player_dir == 'S')
			cub->player_data->rot_angle = (3 * M_PI) / 2;
		if (cub->player_dir == 'W')
			cub->player_data->rot_angle = 0;
	}
	cub->player_movex = cub->player_data->x;
	cub->player_movey = cub->player_data->y;
}

int	init_data(t_cub3d_data *cub)
{
	cub->t_no = NULL;
	cub->t_so = NULL;
	cub->t_we = NULL;
	cub->t_ea = NULL;
	cub->c_c = NULL;
	cub->c_f = NULL;
	cub->line = NULL;
	cub->player_dir = '\0';
	cub->t_index = 0;
	cub->m_index = 0;
	return (0);
}
