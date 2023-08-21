/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nouahidi <nouahidi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 13:21:47 by lsabik            #+#    #+#             */
/*   Updated: 2023/07/28 13:03:41 by nouahidi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	ft_mouse(void *param)
{
	t_cub3d_data	*cub;
	int				x;
	double			turn_dir;

	cub = param;
	x = WIDTH / 2;
	turn_dir = 0;
	mlx_get_mouse_pos(cub->mlx, &cub->mouse_x, &cub->mouse_y);
	cub->player->rot_angle += (cub->mouse_x - 500) / 500.0 * SENSE;
	mlx_set_mouse_pos(cub->mlx, 500, 500);
}

char	*get_current_time(void)
{
	time_t		t;
	struct tm	*tm_info;
	static char	buffer[6];

	time(&t);
	tm_info = localtime(&t);
	strftime(buffer, sizeof(buffer), "%H:%M", tm_info);
	return (buffer);
}

void	display_current_time(t_cub3d_data *cub)
{
	char	*current_time;

	current_time = get_current_time();
	cub->time = mlx_put_string(cub->mlx, current_time, WIDTH - 220, 0);
	mlx_resize_image(cub->time, 190, 100);
}

void	put_images_to_window(t_cub3d_data *cub)
{
	mlx_image_to_window(cub->mlx, cub->sky_floor, 0, 0);
	mlx_image_to_window(cub->mlx, cub->map_img, 0, 0);
	mlx_image_to_window(cub->mlx, cub->full_map, 200, 200);
	mlx_image_to_window(cub->mlx, cub->screen_img, 0, 0);
	mlx_image_to_window(cub->mlx, cub->mode, (WIDTH / 2) - \
		(cub->mode->width / 2), HEIGHT - cub->mode->height);
	mlx_image_to_window(cub->mlx, cub->minimap, 0, HEIGHT - MP_HEIGHT);
	mlx_image_to_window(cub->mlx, cub->intro, 0, 0);
}

int	main(int ac, char **av)
{
	t_cub3d_data	*cub;

	cub = ft_calloc(1, sizeof(t_cub3d_data));
	if (map_parsing(cub, ac, av) == FAILURE)
		return (FAILURE);
	ft_mlx_init(cub);
	sky_floor(cub, 0, 0);
	read_color(cub);
	cub_img(cub);
	display_current_time(cub);
	add_sounds(cub, W);
	put_images_to_window(cub);
	mlx_set_cursor_mode(cub->mlx, MLX_MOUSE_HIDDEN);
	mlx_cursor_hook(cub->mlx, (void *)ft_mouse, cub);
	mlx_loop_hook(cub->mlx, ft_hook, cub);
	mlx_loop(cub->mlx);
	mlx_terminate(cub->mlx);
	free_all(cub);
	return (SUCCESS);
}
