/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprites.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nouahidi <nouahidi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/15 13:45:31 by lsabik            #+#    #+#             */
/*   Updated: 2023/07/28 15:57:35 by nouahidi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	check_texture_bounds(t_spinfos *sp, mlx_texture_t *sp_text)
{
	unsigned int	texel_index;

	texel_index = (sp_text->width * sp->text_y) + sp->text_x;
	return (texel_index > 0 && texel_index < (sp_text->width \
		* sp_text->height));
}

void	render_vert_stripe(t_cub3d_data *cub, int x, t_sprites sp, \
		mlx_texture_t *sp_text)
{
	int				y;
	unsigned int	texelcolor;
	unsigned int	*wall_text;

	y = cub->sp->sp_topy;
	while (y < cub->sp->sp_bottomy)
	{
		if (x >= 0 && x < WIDTH && y >= 0 && y < HEIGHT)
		{
			calcs_offset_y(cub, y, sp_text);
			if (sp.dist < cub->ray_dist[x])
			{
				wall_text = cub->walltexture[cub->tmp_vl];
				if (check_texture_bounds(cub->sp, sp_text))
				{
					texelcolor = wall_text[(sp_text->width * \
					cub->sp->text_y) + cub->sp->text_x];
					if (texelcolor != 0x0000000)
						mlx_put_pixel(cub->map_img, x, y, texelcolor);
				}
			}
		}
		y++;
	}
}

void	render_vis_sprites(t_cub3d_data *cub, t_sprites *vis_sprites, \
		int vis_sp)
{
	int				i;
	int				x;
	t_sprites		sprite;
	mlx_texture_t	*sp_text;

	i = 0;
	while (i < vis_sp)
	{
		sp_text = vis_sprites[i].sp_text;
		sprite = vis_sprites[i];
		calc_sprite_dims(cub, sprite);
		x = cub->sp->sp_leftx;
		cub->tmp_vl = vis_sprites[i].index;
		while (x < cub->sp->sp_rightx)
		{
			calcs_offset_x(cub, x, sp_text);
			render_vert_stripe(cub, x, sprite, sp_text);
			x++;
		}
		i++;
	}
}

void	render_sprite(t_cub3d_data *cub, int i)
{
	int			vis_sp;
	double		angel_sp_pl;
	t_sprites	*vis_sprites;

	vis_sp = 0;
	vis_sprites = malloc(sizeof(t_sprites) * cub->sprite_num);
	while (++i < cub->sprite_num)
	{
		cub->sprites[i].dist = 0;
		angel_sp_pl = cub->player->rot_angle - atan2(cub->player->y - \
			cub->sprites[i].y, cub->player->x - cub->sprites[i].x);
		norm_angle(&angel_sp_pl);
		if (angel_sp_pl < (FOV_ANGLE / 2) + EPSILON)
		{
			cub->sprites[i].visible = true;
			cub->sprites[i].angle = angel_sp_pl;
			cub->sprites[i].dist = distance_between_points(cub->sprites[i].x, \
				cub->sprites[i].y, cub->player->x, cub->player->y);
			vis_sprites[vis_sp] = cub->sprites[i];
			vis_sp++;
		}
		else
			cub->sprites[i].visible = false;
	}
	draw_sprites(cub, vis_sprites, vis_sp);
}
