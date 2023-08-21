/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nouahidi <nouahidi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 22:47:32 by lsabik            #+#    #+#             */
/*   Updated: 2023/07/28 15:07:57 by nouahidi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	get_color(int r, int g, int b, int a)
{
	return (r << 24 | g << 16 | b << 8 | a);
}

void	free_all(t_cub3d_data *cub)
{
	free(cub->t_no);
	free(cub->t_so);
	free(cub->t_ea);
	free(cub->t_we);
	free(cub->player);
	free(cub->rays);
	while (*cub->matrice)
	{
		free(*cub->matrice);
		cub->matrice++;
	}
}

void	cast_allrays(t_cub3d_data *cub)
{
	int		i;

	i = 0;
	cub->rays->ray_ang = cub->player->rot_angle - (FOV_ANGLE / 2);
	while (i < NUM_RAYS)
	{
		ray_cast(cub, INT_MAX, INT_MAX);
		renderwallproject(cub, i, index_dir(cub));
		cub->rays->ray_ang += FOV_ANGLE / NUM_RAYS;
		cub->ray_dist[i] = cub->rays->distance;
		i++;
	}
}

void	cub_img(t_cub3d_data *cub)
{
	cub->rays->flag = 0;
	cast_allrays(cub);
	find_sprites(cub, 0, 0, 0);
	render_sprite(cub, -1);
	put_mini_map(cub);
	sprites_animation(cub);
}
