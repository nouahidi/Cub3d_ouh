/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nouahidi <nouahidi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 14:47:32 by lsabik            #+#    #+#             */
/*   Updated: 2023/07/28 14:57:35 by nouahidi         ###   ########.fr       */
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
	cub->rays->ray_ang = cub->player->rot_angle;
	cub->rays->is_rayfacingdown = 0;
	cub->rays->is_rayfacingright = 0;
	cub->rays->is_rayfacingup = 0;
	cub->rays->is_rayfacingleft = 0;
	cub->d_pr_plane = (WIDTH / 2) / tan(FOV_ANGLE / 2);
}

void	init_img(t_cub3d_data *cub)
{
	cub->map_img = mlx_new_image(cub->mlx, WIDTH, HEIGHT);
	cub->full_map = mlx_new_image(cub->mlx, WIDTH_FULLMAP, HEIGHT_FULLMAP);
	cub->minimap = mlx_new_image(cub->mlx, MP_WIDTH, MP_HEIGHT);
	if (!cub->map_img || !cub->full_map || !cub->minimap)
	{
		puts(mlx_strerror(mlx_errno));
		exit(EXIT_FAILURE);
	}
}

void	ft_load_png(t_cub3d_data *cub)
{
	load_png(&(cub->cj[0]), "bonus/images/CJ1.png");
	load_png(&(cub->cj[1]), "bonus/images/CJ2.png");
	load_png(&(cub->cj[2]), "bonus/images/CJ3.png");
	load_png(&(cub->cj[3]), "bonus/images/CJ4.png");
	load_png(&(cub->cj[4]), "bonus/images/CJ5.png");
	load_png(&(cub->cj[5]), "bonus/images/CJ6.png");
	load_png(&(cub->cj[6]), "bonus/images/CJ7.png");
	load_png(&(cub->cj[7]), "bonus/images/CJ8.png");
	load_png(&(cub->cj[8]), "bonus/images/CJ9.png");
	load_png(&(cub->cj[9]), "bonus/images/CJ10.png");
	load_png(&(cub->cj[10]), "bonus/images/CJ11.png");
	load_png(&(cub->cj[11]), "bonus/images/CJ12.png");
	load_png(&(cub->cj[12]), "bonus/images/CJ13.png");
	load_png(&(cub->cj[13]), "bonus/images/CJ14.png");
	load_png(&(cub->cj[14]), "bonus/images/gtatime.png");
	load_png(&(cub->cj[15]), "bonus/images/wallpaper.png");
	load_png(&(cub->cj[16]), "bonus/images/lotoo.png");
}
