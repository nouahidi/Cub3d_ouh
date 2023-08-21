/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyhook_util3.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nouahidi <nouahidi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 13:22:34 by nouahidi          #+#    #+#             */
/*   Updated: 2023/07/28 13:24:43 by nouahidi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	cj_walk(t_cub3d_data *cub)
{
	mlx_delete_image(cub->mlx, cub->mode);
	cub->mode = mlx_texture_to_image(cub->mlx, cub->cj[cub->walk_flag]);
	cub->mode_fg = 0;
}

int	hit_sprite(t_cub3d_data *cub)
{
	int	px;
	int	py;

	px = (int)cub->player->x / W_DM;
	py = (int)cub->player->y / W_DM;
	if (cub->matrice[py][px] == 'Y')
		return (1);
	return (0);
}
