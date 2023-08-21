/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_util.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsabik <lsabik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 00:40:42 by nouahidi          #+#    #+#             */
/*   Updated: 2023/07/27 14:28:13 by lsabik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	ft_mlx_init(t_cub3d_data *cub)
{
	cub->mlx = mlx_init(WIDTH, HEIGHT, "MyCub3D", true);
	if (!cub->mlx)
	{
		puts(mlx_strerror(mlx_errno));
		exit(EXIT_FAILURE);
	}
	init_img(cub);
	cub->walk_flag = 0;
	cub->anim_flag = 5;
	ft_load_png(cub);
	cub->mode = mlx_texture_to_image(cub->mlx, cub->cj[cub->walk_flag]);
	cub->mode_fg = 0;
	cub->screen_img = mlx_texture_to_image(cub->mlx, cub->cj[14]);
	cub->intro = mlx_texture_to_image(cub->mlx, cub->cj[15]);
	init_data_player(cub);
	init_ray_data(cub);
	cub->openflag = 1;
	cub->doorflag = 0;
	cub->tm = 1;
	cub->mouse_x = WIDTH / 2;
	cub->mouse_y = HEIGHT / 2;
}

void	init_data_player(t_cub3d_data *cub)
{
	cub->player = ft_calloc(1, sizeof(t_data_player));
	if (cub->matrice[cub->player_y][cub->player_x])
	{
		cub->player->x = cub->player_x * W_DM + 32;
		cub->player->y = cub->player_y * W_DM + 32;
		if (cub->player_dir == 'E')
			cub->player->rot_angle = M_PI;
		if (cub->player_dir == 'N')
			cub->player->rot_angle = M_PI / 2;
		if (cub->player_dir == 'S')
			cub->player->rot_angle = (3 * M_PI) / 2;
		if (cub->player_dir == 'W')
			cub->player->rot_angle = 0;
	}
}

int	init_data(t_cub3d_data *cub)
{
	cub->t_no = NULL;
	cub->t_so = NULL;
	cub->t_we = NULL;
	cub->t_ea = NULL;
	cub->c_c = NULL;
	cub->c_f = NULL;
	cub->line = NULL;
	cub->player_dir = '\0';
	cub->t_index = 0;
	cub->m_index = 0;
	return (0);
}
