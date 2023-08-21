/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   macros.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nouahidi <nouahidi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 17:19:25 by lsabik            #+#    #+#             */
/*   Updated: 2023/07/28 12:43:33 by nouahidi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MACROS_H
# define MACROS_H

# define CLR_RMV "\033[0m"
# define RED "\033[1;31m"
# define GREEN "\033[1;32m"
# define YELLOW "\033[1;33m"
# define BLUE "\033[1;34m"
# define CYAN "\033[1;36m"
# define WIDTH 1580
# define HEIGHT 1500
# define WALL_DIMENSION 32
# define TEXTUR_HEIGHT WALL_DIMENSION
# define TEXTUR_WIDTH WALL_DIMENSION
# define NUM_RAYS WIDTH
# define FOV_ANGLE 1.0471975512
# define P_RADIUS  8.0
# define MV_SPEED 5.0
# define ROT_SPEED 0.05235987756
# define MINIMAP_SCALE_FACTOR 0.3
# define WALL_STRIP_WIDTH 1
# define PLAYER_SIZE 2

# define ORANGE_MP 0xFF7000FF
# define BLACK_MP 0x000000FF
# define WHITE_MP 0xFFFFFFFF
# define RED_MP 0xFF0000FF
# define GREEN_MP 0x00FF00FF
# define BLUE_MP 0x0000FFFF
# define YELLOW_MP 0xFFFF00FF
# define CYAN_MP 0x00FFFFFF
# define PURPLE_MP 0x800080FF

# define FAILURE -1
# define SUCCESS 1

# define VERTICAL 0
# define HORIZONTAL 1

# define T_NO 1
# define T_SO 2
# define T_WE 3
# define T_EA 4
# define C_F 5
# define C_C 6
# define M_W 7
# define M_E 8
# define M_P 9
# define RET_LINE 10

# define INVALIDE_ARGS "\033[1;31mInvalid arguments!!\n\033[0;34mThe \
correct format is: ./cub3d map_file.cub"
# define NON_EXIT_FILE "\033[1;31mNON Existing File!!\n\033[0;34mThe \
correct format is :<< ./cub3d map_file.cub>>"
# define TEXTURE_ERROR "\033[1;31mTexture Error!!\033[0;34m"
# define CONFIG_ERROR "\033[1;31mConfig File Error!!\033[0;34m"

#endif