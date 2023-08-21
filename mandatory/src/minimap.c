/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsabik <lsabik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 22:47:32 by lsabik            #+#    #+#             */
/*   Updated: 2023/07/26 21:01:15 by lsabik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	cast_allrays(t_cub3d_data *cub)
{
	int		i;

	i = 0;
	cub->rays->ray_ang = cub->player_data->rot_angle - (FOV_ANGLE / 2);
	while (i < NUM_RAYS)
	{
		ray_cast(cub);
		renderwallproject(cub, i);
		cub->rays->ray_ang += FOV_ANGLE / NUM_RAYS;
		i++;
	}
}

int	distance(int i, int j, int x, int y)
{
	return (sqrt(pow(x - i, 2) + pow(y - j, 2)));
}

void	cub_img(t_cub3d_data *cub)
{
	cub->map_img = mlx_new_image(cub->mlx, WIDTH, HEIGHT);
	if (!cub->map_img)
	{
		puts(mlx_strerror(mlx_errno));
		exit(EXIT_FAILURE);
	}
	cast_allrays(cub);
}
