/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycastingutils2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nouahidi <nouahidi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 12:08:26 by nouahidi          #+#    #+#             */
/*   Updated: 2023/07/26 23:48:47 by nouahidi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

double	fix_fishbowl(t_cub3d_data *cub)
{
	if (cub->rays->distance == 0)
		cub->rays->distance = 0.1;
	return (cub->rays->distance * \
	cos(cub->rays->ray_ang - cub->player_data->rot_angle));
}

void	renderwall(t_cub3d_data *cub, int i)
{
	unsigned int	texelcolor;
	int				y;

	y = cub->rays->walltoppixel;
	if (cub->rays->hit_verti)
		cub->rays->textoffsetx = (int)cub->rays->wallhit_y % WALL_DIMENSION;
	else
		cub->rays->textoffsetx = (int)cub->rays->wallhit_x % WALL_DIMENSION;
	cub->rays->text_wall = get_dir(cub);
	while (y < cub->rays->wallbottom)
	{
		cub->rays->dis_fromtop = y + (cub->rays->wl_strip_h / 2) - (HEIGHT / 2);
		cub->rays->textureoffsety = cub->rays->dis_fromtop * \
		((float)TEXTUR_HEIGHT / cub->rays->wl_strip_h);
		texelcolor = cub->rays->text_wall[(TEXTUR_WIDTH * \
		cub->rays->textureoffsety) + cub->rays->textoffsetx];
		mlx_put_pixel(cub->map_img, i, y, texelcolor);
		y++;
	}
}

void	renderwallproject(t_cub3d_data *cub, int i)
{
	double	corr_dis;
	double	d_pr_plane;

	corr_dis = fix_fishbowl(cub);
	d_pr_plane = (WIDTH / 2) / tan(FOV_ANGLE / 2);
	cub->rays->pr_wallheight = (WALL_DIMENSION / corr_dis) * d_pr_plane;
	cub->rays->wl_strip_h = (int) cub->rays->pr_wallheight;
	cub->rays->walltoppixel = (HEIGHT / 2) - (cub->rays->wl_strip_h / 2);
	if (cub->rays->walltoppixel < 0)
		cub->rays->walltoppixel = 0;
	cub->rays->wallbottom = (HEIGHT / 2) + (cub->rays->wl_strip_h / 2);
	if (cub->rays->wallbottom > HEIGHT)
		cub->rays->wallbottom = HEIGHT;
	renderwall(cub, i);
}
