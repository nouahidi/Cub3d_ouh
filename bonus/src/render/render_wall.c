/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_wall.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nouahidi <nouahidi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 17:08:54 by lsabik            #+#    #+#             */
/*   Updated: 2023/07/28 15:40:49 by nouahidi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	index_dir(t_cub3d_data *cub)
{
	int	i;

	i = 0;
	if (cub->rays->is_rayfacingup && !cub->rays->hit_verti \
		&& cub->rays->flag == 1)
		i = 4;
	else if (cub->rays->is_rayfacingup && !cub->rays->hit_verti)
		i = 0;
	else if (cub->rays->is_rayfacingdown && !cub->rays->hit_verti \
		&& cub->rays->flag == 1)
		i = 4;
	else if (cub->rays->is_rayfacingright && cub->rays->hit_verti \
		&& cub->rays->flag == 1)
		i = 4;
	else if (cub->rays->is_rayfacingleft && cub->rays->hit_verti && \
		cub->rays->flag == 1)
		i = 4;
	else if (cub->rays->is_rayfacingdown && !cub->rays->hit_verti)
		i = 1;
	else if (cub->rays->is_rayfacingright && cub->rays->hit_verti)
		i = 2;
	else if (cub->rays->is_rayfacingleft && cub->rays->hit_verti)
		i = 3;
	cub->rays->flag = 0;
	return (i);
}

void	caluc_offest_x(t_cub3d_data *cub, int f)
{
	if (cub->rays->hit_verti)
		cub->text_offsetx = (cub->rays->wallhit_y / W_DM \
		- (int)cub->rays->wallhit_y / W_DM) * cub->text[f]->width;
	else
		cub->text_offsetx = (cub->rays->wallhit_x / W_DM - \
		(int)cub->rays->wallhit_x / W_DM) * cub->text[f]->width;
}

double	fix_fishbowl(t_cub3d_data *cub)
{
	if (cub->rays->distance == 0)
		cub->rays->distance = 0.1;
	return (cub->rays->distance *= cos(cub->rays->ray_ang - \
		cub->player->rot_angle));
}

void	renderwallproject(t_cub3d_data *cub, int x, int text_index)
{
	int				y;
	unsigned int	*text_wall;
	double			corr_dis;
	unsigned int	texelcolor;

	corr_dis = fix_fishbowl(cub);
	cub->wallstripheight = (int)((W_DM / corr_dis) * cub->d_pr_plane);
	cub->walltop = (HEIGHT / 2) - (cub->wallstripheight / 2);
	cub->wallbottom = (HEIGHT / 2) + (cub->wallstripheight / 2);
	text_wall = cub->walltexture[text_index];
	caluc_offest_x(cub, text_index);
	y = cub->walltop;
	while (y < cub->wallbottom)
	{
		if (x >= 0 && x < WIDTH && y >= 0 && y < HEIGHT)
		{
			cub->text_offsety = (y - cub->walltop) * \
				((double)cub->text[text_index]->height / cub->wallstripheight);
			texelcolor = text_wall[(cub->text[text_index]->width \
				* cub->text_offsety) + cub->text_offsetx];
			mlx_put_pixel(cub->map_img, x, y, texelcolor);
		}
		y++;
	}
}
