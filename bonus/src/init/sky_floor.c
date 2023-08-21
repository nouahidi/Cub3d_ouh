/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sky_floor.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nouahidi <nouahidi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/14 18:34:42 by lsabik            #+#    #+#             */
/*   Updated: 2023/07/28 12:06:04 by nouahidi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	sky_floor(t_cub3d_data *cub, int x, int y)
{
	cub->sky_floor = mlx_new_image(cub->mlx, WIDTH, HEIGHT);
	if (!cub->sky_floor)
	{
		puts(mlx_strerror(mlx_errno));
		exit(EXIT_FAILURE);
	}
	while (x < WIDTH)
	{
		y = 0;
		while (y < HEIGHT)
		{
			if (y < HEIGHT / 2)
				mlx_put_pixel(cub->sky_floor, x, y, get_color(cub->c_c->b, \
					cub->c_c->g, cub->c_c->r, 255));
			else
				mlx_put_pixel(cub->sky_floor, x, y, get_color(cub->c_f->b, \
					cub->c_f->g, cub->c_f->r, 255));
			y++;
		}
		x++;
	}
	free(cub->c_c);
	free(cub->c_f);
}

void	png_info(t_cub3d_data *cub, int num, mlx_texture_t *text)
{
	unsigned int	i;
	unsigned int	j;

	i = 0;
	j = 0;
	cub->walltexture[num] = ft_calloc(1, ((text->width * text->height * \
		+ 1) * sizeof(unsigned int)));
	while (j < (text->height * text->width))
	{
		cub->walltexture[num][j++] = get_color(text->pixels[i], \
			text->pixels[i + 1], text->pixels[i + 2], text->pixels[i + 3]);
		if (i < (text->height * text->width * 4) - 4)
			i += 4;
	}
}

void	load_png(mlx_texture_t **text, char *path)
{
	*text = mlx_load_png(path);
	if (!*text)
	{
		puts(mlx_strerror(mlx_errno));
		exit(EXIT_FAILURE);
	}
}

void	load_sprites(t_cub3d_data *cub)
{
	load_png(&(cub->text[4]), "bonus/images/black_door.png");
	load_png(&(cub->text[5]), "bonus/images/gta_femal1.png");
	load_png(&(cub->text[6]), "bonus/images/gta_femal2.png");
	load_png(&(cub->text[7]), "bonus/images/gta_femal3.png");
	load_png(&(cub->text[8]), "bonus/images/gta_femal4.png");
	load_png(&(cub->text[9]), "bonus/images/gta_femal5.png");
	load_png(&(cub->text[10]), "bonus/images/gta_femal6.png");
	load_png(&(cub->text[11]), "bonus/images/gta_femal7.png");
	load_png(&(cub->text[12]), "bonus/images/gta_femal8.png");
	load_png(&(cub->text[13]), "bonus/images/gta_femal9.png");
	load_png(&(cub->text[14]), "bonus/images/gta_femal10.png");
	load_png(&(cub->text[15]), "bonus/images/gta_femal11.png");
	load_png(&(cub->text[16]), "bonus/images/gta_femal12.png");
	load_png(&(cub->text[17]), "bonus/images/gta_femal13.png");
	load_png(&(cub->text[18]), "bonus/images/gta_femal14.png");
	load_png(&(cub->text[19]), "bonus/images/gta_femal15.png");
	load_png(&(cub->text[20]), "bonus/images/gta_femal16.png");
	load_png(&(cub->text[21]), "bonus/images/gta_femal17.png");
	load_png(&(cub->text[22]), "bonus/images/gta_femal18.png");
	load_png(&(cub->text[23]), "bonus/images/gta_femal19.png");
	load_png(&(cub->text[24]), "bonus/images/gta_femal20.png");
	load_png(&(cub->text[25]), "bonus/images/ferrari.png");
	load_png(&(cub->text[26]), "bonus/images/tree.png");
	load_png(&(cub->text[27]), "bonus/images/light.png");
	load_png(&(cub->text[28]), "bonus/images/lights.png");
}

void	read_color(t_cub3d_data *cub)
{
	int	i;

	load_png(&(cub->text[0]), cub->t_no);
	load_png(&(cub->text[1]), cub->t_so);
	load_png(&(cub->text[2]), cub->t_we);
	load_png(&(cub->text[3]), cub->t_ea);
	load_sprites(cub);
	i = -1;
	while (++i < 29)
		png_info(cub, i, cub->text[i]);
}
