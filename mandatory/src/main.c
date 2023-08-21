/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nouahidi <nouahidi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 13:21:47 by lsabik            #+#    #+#             */
/*   Updated: 2023/07/27 00:02:19 by nouahidi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	main(int ac, char **av)
{
	t_cub3d_data	*cub;

	cub = ft_calloc(1, sizeof(t_cub3d_data));
	if (map_parsing(cub, ac, av) == FAILURE)
		return (FAILURE);
	ft_mlx_init(cub);
	sky_floor(cub, 0, 0);
	init_texture(cub);
	cub_img(cub);
	mlx_image_to_window(cub->mlx, cub->sky_floor, 0, 0);
	mlx_image_to_window(cub->mlx, cub->map_img, 0, 0);
	mlx_loop_hook(cub->mlx, ft_hook, cub);
	mlx_loop(cub->mlx);
	mlx_terminate(cub->mlx);
	return (SUCCESS);
}
