/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyhook.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nouahidi <nouahidi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/08 10:13:01 by nouahidi          #+#    #+#             */
/*   Updated: 2023/07/28 13:53:11 by nouahidi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	ft_clear_window(t_cub3d_data *cub)
{
	if (mlx_is_key_down(cub->mlx, MLX_KEY_ESCAPE))
	{
		kill(cub->pid, SIGKILL);
		mlx_close_window(cub->mlx);
		exit(SUCCESS);
	}
	ft_memset(cub->map_img->pixels, 0,
		cub->map_img->width * cub->map_img->height * sizeof(int32_t));
	ft_memset(cub->full_map->pixels, 0, cub->full_map->width * \
		cub->full_map->height * sizeof(int32_t));
	ft_memset(cub->minimap->pixels, 0, cub->minimap->width * \
		cub->minimap->height * sizeof(int32_t));
}

int	ft_change_mode(t_cub3d_data *cub, char c1, char c2)
{
	if (cub->matrice[((int)cub->player->y / W_DM) + 1] \
		[(int)cub->player->x / W_DM] == c1)
		cub->matrice[((int)cub->player->y / W_DM) + 1] \
			[(int)cub->player->x / W_DM] = c2;
	else if (cub->matrice[((int)cub->player->y / W_DM) - 1] \
		[(int)cub->player->x / W_DM] == c1)
		cub->matrice[((int)cub->player->y / W_DM) - 1] \
			[(int)cub->player->x / W_DM] = c2;
	else if (cub->matrice[(int)cub->player->y / W_DM] \
		[((int)cub->player->x / W_DM) + 1] == c1)
		cub->matrice[(int)cub->player->y / W_DM] \
			[((int)cub->player->x / W_DM) + 1] = c2;
	else if (cub->matrice[(int)cub->player->y / W_DM] \
		[((int)cub->player->x / W_DM) - 1] == c1)
		cub->matrice[(int)cub->player->y / W_DM] \
			[((int)cub->player->x / W_DM) - 1] = c2;
	else
		return (0);
	return (1);
}

void	ft_drive(t_cub3d_data *cub)
{
	if (mlx_is_key_down(cub->mlx, MLX_KEY_F) && !cub->mode_fg)
	{
		if (ft_change_mode(cub, 'y', '0'))
		{
			mlx_delete_image(cub->mlx, cub->mode);
			cub->mode = mlx_texture_to_image(cub->mlx, cub->cj[16]);
			cub->mode_fg = 1;
			add_sounds(cub, R);
			mlx_image_to_window(cub->mlx, cub->mode, 0, 0);
			mlx_image_to_window(cub->mlx, cub->minimap, 0, HEIGHT - MP_HEIGHT);
		}
	}
	else if (mlx_is_key_down(cub->mlx, MLX_KEY_V) && cub->mode_fg)
	{
		if (ft_change_mode(cub, '0', 'y'))
		{
			mlx_delete_image(cub->mlx, cub->mode);
			cub->mode = mlx_texture_to_image(cub->mlx, cub->cj[cub->walk_flag]);
			cub->mode_fg = 0;
			kill(cub->pid, SIGKILL);
			mlx_image_to_window(cub->mlx, cub->mode, (WIDTH / 2) - \
		(cub->mode->width / 2), HEIGHT - cub->mode->height);
		}
	}
}

void	ft_hook_cont(t_cub3d_data *cub)
{
	static int		time;

	if (mlx_is_key_down(cub->mlx, MLX_KEY_SPACE))
	{
		kill(cub->pid, SIGKILL);
		mlx_delete_image(cub->mlx, cub->intro);
	}
	if (time == 100)
	{
		ft_memset(cub->time->pixels, 0, cub->time->width * \
		cub->time->height * sizeof(int32_t));
		time = 0;
		display_current_time(cub);
	}
	time++;
	ft_tur_direction(cub);
	ft_door(cub);
	cub_img(cub);
	if (mlx_is_key_down(cub->mlx, MLX_KEY_M))
		setting_map(cub);
}

void	ft_hook(void *param)
{
	t_cub3d_data	*cub;

	cub = param;
	ft_clear_window(cub);
	if (mlx_is_key_down(cub->mlx, MLX_KEY_F) || \
	mlx_is_key_down(cub->mlx, MLX_KEY_V))
		ft_drive(cub);
	if (mlx_is_key_down(cub->mlx, MLX_KEY_S))
		walk_direction(cub, 1);
	if (mlx_is_key_down(cub->mlx, MLX_KEY_W))
		walk_direction(cub, -1);
	if (mlx_is_key_down(cub->mlx, MLX_KEY_D))
		side_direction(cub, -1);
	if (mlx_is_key_down(cub->mlx, MLX_KEY_A))
		side_direction(cub, 1);
	if (mlx_is_key_down(cub->mlx, MLX_KEY_G))
		add_sounds(cub, G);
	if (mlx_is_key_down(cub->mlx, MLX_KEY_K) && cub->mode_fg)
		add_sounds(cub, K);
	ft_hook_cont(cub);
}
