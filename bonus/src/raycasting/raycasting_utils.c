/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nouahidi <nouahidi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/15 12:11:47 by lsabik            #+#    #+#             */
/*   Updated: 2023/07/22 16:05:29 by nouahidi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	protect_matrice(double touchX, double touchY, t_cub3d_data *cub)
{
	int	x;
	int	y;

	x = floor(touchX / W_DM);
	y = floor(touchY / W_DM);
	if (x < 0 || x > cub->len_i || y < 0 || y > cub->len_j - 1)
		return (1);
	if (cub->matrice[y][x] == 'D')
		return (2);
	return (cub->matrice[y][x] == '1');
}

void	raycasting_init(t_cub3d_data *cub)
{
	cub->rays->wallhit_x = 0;
	cub->rays->wallhit_y = 0;
	cub->rays->distance = 0;
	cub->rays->ray_ang = normalizeangle(cub->rays->ray_ang);
	cub->rays->hor_wallhitx = WIDTH * 2;
	cub->rays->hor_wallhity = HEIGHT * 2;
	cub->rays->vert_wallhitx = WIDTH * 2;
	cub->rays->vert_wallhity = HEIGHT * 2;
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
	hor_intersec(cub);
	vert_intersec(cub);
}

double	distance_between_points(double x1, double y1, double x2, double y2)
{
	return (sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2)));
}

void	calcs_vertintercept(t_cub3d_data *cub)
{
	cub->rays->foundverzwallhit = 0;
	cub->rays->xintercept = floor(cub->player->x / W_DM) * \
		W_DM;
	if (cub->rays->is_rayfacingright)
		cub->rays->xintercept += W_DM;
	cub->rays->yintercept = cub->player->y + (cub->rays->xintercept - \
		cub->player->x) * tan(cub->rays->ray_ang);
	cub->rays->xstep = W_DM;
	cub->rays->ystep = W_DM * tan(cub->rays->ray_ang);
	cub->rays->vert_wallhitx = cub->rays->xintercept;
	cub->rays->vert_wallhity = cub->rays->yintercept ;
}

void	calcs_horintercept(t_cub3d_data *cub)
{
	cub->rays->foundverzwallhit = 0;
	cub->rays->yintercept = floor(cub->player->y / W_DM) \
		* W_DM;
	if (cub->rays->is_rayfacingdown)
		cub->rays->yintercept += W_DM;
	cub->rays->xintercept = cub->player->x + (cub->rays->yintercept \
		- cub->player->y) / tan(cub->rays->ray_ang);
	cub->rays->ystep = W_DM;
	cub->rays->xstep = W_DM / tan(cub->rays->ray_ang);
	cub->rays->hor_wallhitx = cub->rays->xintercept;
	cub->rays->hor_wallhity = cub->rays->yintercept;
}
