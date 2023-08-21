/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nouahidi <nouahidi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 15:59:00 by lsabik            #+#    #+#             */
/*   Updated: 2023/07/26 23:47:34 by nouahidi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	hor_intersec(t_cub3d_data *cub)
{
	calcs_horintercept(cub);
	cub->rays->hor_wallhitx = cub->rays->xintercept;
	cub->rays->hor_wallhity = cub->rays->yintercept;
	if (cub->rays->is_rayfacingup)
	{
		cub->rays->ystep *= -1;
		cub->rays->xstep *= -1;
		cub->rays->hor_wallhity -= 0.01;
	}
	while (1)
	{
		if (protect_matrice(cub->rays->hor_wallhitx, \
			cub->rays->hor_wallhity, cub))
		{
			if (cub->rays->is_rayfacingup)
				cub->rays->hor_wallhity += 0.01;
			cub->rays->foundhorzwallhit = 1;
			break ;
		}
		else
		{
			cub->rays->hor_wallhitx += cub->rays->xstep;
			cub->rays->hor_wallhity += cub->rays->ystep;
		}
	}
}

void	vert_intersec(t_cub3d_data *cub)
{
	calcs_vertintercept(cub);
	cub->rays->vert_wallhitx = cub->rays->xintercept;
	cub->rays->vert_wallhity = cub->rays->yintercept ;
	if (cub->rays->is_rayfacingleft)
	{
		cub->rays->xstep *= -1;
		cub->rays->ystep *= -1;
		cub->rays->vert_wallhitx -= 0.01;
	}
	while (1)
	{
		if (protect_matrice(cub->rays->vert_wallhitx, \
			cub->rays->vert_wallhity, cub))
		{
			if (cub->rays->is_rayfacingleft)
				cub->rays->vert_wallhitx += 0.01;
			cub->rays->foundverzwallhit = 1;
			break ;
		}
		else
		{
			cub->rays->vert_wallhitx += cub->rays->xstep;
			cub->rays->vert_wallhity += cub->rays->ystep;
		}
	}
}

void	ft_intersection(t_cub3d_data *cub, double hz_hdis, double vr_hdis)
{
	if (vr_hdis < hz_hdis)
	{
		cub->rays->wallhit_x = cub->rays->vert_wallhitx;
		cub->rays->wallhit_y = cub->rays->vert_wallhity;
		cub->rays->distance = vr_hdis;
		cub->rays->hit_verti = 1;
	}
	else
	{
		cub->rays->wallhit_x = cub->rays->hor_wallhitx;
		cub->rays->wallhit_y = cub->rays->hor_wallhity;
		cub->rays->distance = hz_hdis;
		cub->rays->hit_verti = 0;
	}
}

void	ray_cast(t_cub3d_data *cub)
{
	double	horzhitdistance;
	double	vertzhitdistance;

	cub->rays->wallhit_x = 0;
	cub->rays->wallhit_y = 0;
	cub->rays->distance = 0;
	cub->rays->ray_ang = normalizeangle(cub->rays->ray_ang);
	raycasting_init(cub);
	hor_intersec(cub);
	vert_intersec(cub);
	horzhitdistance = INT_MAX;
	vertzhitdistance = INT_MAX;
	if (cub->rays->foundhorzwallhit)
		horzhitdistance = distance_between_points(cub->player_data->x, \
		cub->player_data->y, cub->rays->hor_wallhitx, cub->rays->hor_wallhity);
	if (cub->rays->foundverzwallhit)
		vertzhitdistance = distance_between_points(cub->player_data->x, \
		cub->player_data->y, cub->rays->vert_wallhitx, \
		cub->rays->vert_wallhity);
	ft_intersection(cub, horzhitdistance, vertzhitdistance);
}

unsigned int	*get_dir(t_cub3d_data *cub)
{
	unsigned int	*wall_text;

	wall_text = NULL;
	if (cub->rays->is_rayfacingup && !cub->rays->hit_verti)
		wall_text = cub->walltexture[0];
	else if (cub->rays->is_rayfacingdown && !cub->rays->hit_verti)
		wall_text = cub->walltexture[1];
	else if (cub->rays->is_rayfacingright && cub->rays->hit_verti)
		wall_text = cub->walltexture[2];
	else if (cub->rays->is_rayfacingleft && cub->rays->hit_verti)
		wall_text = cub->walltexture[3];
	return (wall_text);
}
