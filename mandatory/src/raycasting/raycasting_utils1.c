/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_utils1.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nouahidi <nouahidi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 12:05:37 by nouahidi          #+#    #+#             */
/*   Updated: 2023/07/26 23:47:45 by nouahidi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	protect_matrice(double touchX, double touchY, t_cub3d_data *cub)
{
	int	x;
	int	y;

	x = floor(touchX / WALL_DIMENSION);
	y = floor(touchY / WALL_DIMENSION);
	if (x < 0 || x > cub->len_i || y < 0 || y > cub->len_j - 1)
		return (1);
	return (cub->matrice[y][x] == '1');
}

void	raycasting_init(t_cub3d_data *cub)
{
	cub->rays->hor_wallhitx = INT_MAX;
	cub->rays->hor_wallhity = INT_MAX;
	cub->rays->vert_wallhitx = INT_MAX;
	cub->rays->vert_wallhity = INT_MAX;
	if (cub->rays->ray_ang > 0 && cub->rays->ray_ang < M_PI)
		cub->rays->is_rayfacingup = 1;
	else
		cub->rays->is_rayfacingup = 0;
	cub->rays->is_rayfacingdown = !cub->rays->is_rayfacingup;
	if (cub->rays->ray_ang < M_PI / 2 || cub->rays->ray_ang > (3 * M_PI) / 2)
		cub->rays->is_rayfacingleft = 1;
	else
		cub->rays->is_rayfacingleft = 0;
	cub->rays->is_rayfacingright = !cub->rays->is_rayfacingleft;
}

double	distance_between_points(double x1, double y1, double x2, double y2)
{
	return (sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2)));
}

void	calcs_vertintercept(t_cub3d_data *cub)
{
	cub->rays->foundverzwallhit = 0;
	cub->rays->xintercept = floor(cub->player_data->x / WALL_DIMENSION) * \
		WALL_DIMENSION;
	if (cub->rays->is_rayfacingright)
		cub->rays->xintercept += WALL_DIMENSION;
	cub->rays->yintercept = cub->player_data->y + (cub->rays->xintercept - \
		cub->player_data->x) * tan(cub->rays->ray_ang);
	cub->rays->xstep = WALL_DIMENSION;
	cub->rays->ystep = WALL_DIMENSION * tan(cub->rays->ray_ang);
}

void	calcs_horintercept(t_cub3d_data *cub)
{
	cub->rays->foundverzwallhit = 0;
	cub->rays->yintercept = floor(cub->player_data->y / WALL_DIMENSION) \
		* WALL_DIMENSION;
	if (cub->rays->is_rayfacingdown)
		cub->rays->yintercept += WALL_DIMENSION;
	cub->rays->xintercept = cub->player_data->x + (cub->rays->yintercept \
		- cub->player_data->y) / tan(cub->rays->ray_ang);
	cub->rays->ystep = WALL_DIMENSION;
	cub->rays->xstep = WALL_DIMENSION / tan(cub->rays->ray_ang);
}
