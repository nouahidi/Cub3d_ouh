/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nouahidi <nouahidi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 22:54:53 by lsabik            #+#    #+#             */
/*   Updated: 2023/07/28 12:43:46 by nouahidi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "macros.h"
# include "MLX42/MLX42.h"
# include <fcntl.h>
# include <limits.h>
# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct sprites
{
	int		text;
	double	x;
	double	y;
	double	dist;
	double	angle;
}				t_sprites;

typedef struct rays
{
	double			ray_ang;
	double			is_rayfacingdown;
	double			is_rayfacingup;
	double			is_rayfacingright;
	double			is_rayfacingleft;
	double			yintercept;
	double			xintercept;
	double			ystep;
	double			xstep;
	int				foundhorzwallhit;
	double			hor_wallhitx;
	double			hor_wallhity;
	int				foundverzwallhit;
	double			vert_wallhitx;
	double			vert_wallhity;
	double			hit_verti;
	double			distance;
	double			wallhit_x;
	double			wallhit_y;
	int				wl_strip_h;
	int				walltoppixel;
	int				wallbottom;
	int				textureoffsety;
	int				textoffsetx;
	int				dis_fromtop;
	double			pr_wallheight;
	unsigned int	*text_wall;
}				t_ray_data;

typedef struct s_map_color
{
	int			r;
	int			g;
	int			b;
}				t_map_color;

typedef struct player_movement
{
	double	x;
	double	y;
	int		i;
	int		j;
	double	rot_angle;
}				t_data_player;

typedef struct cub3d_data
{
	mlx_t			*mlx;
	char			*t_no;
	char			*t_so;
	char			*t_we;
	char			*t_ea;
	char			**matrice;
	int				t_index;
	int				m_index;
	char			*line;
	int				player_x;
	int				player_y;
	char			player_dir;
	int				len_i;
	int				len_j;
	unsigned int	*texture;
	unsigned int	*walltexture[4];
	double			player_movex;
	double			player_movey;
	mlx_texture_t	*text[4];
	t_ray_data		*rays;
	t_map_color		*c_f;
	t_map_color		*c_c;
	mlx_image_t		*sky_floor;
	mlx_image_t		*map_img;
	t_data_player	*player_data;
}					t_cub3d_data;

// UTILS
int				ft_strcmp(char *s1, char *s2);
void			ft_putstr(char *s);
char			*ft_strdup(char *s1);
int				ft_strlen(char *s);
int				ft_strchr(char *s, char c);
char			*ft_strjoin(char *s1, char *s2);
char			*ft_substr(char *s, unsigned int start, int len);
char			*ft_strtrim(char *s1, char *set);
int				ft_isspace(char str);
void			*ft_calloc(size_t count, size_t size);
void			*ft_memset(void *b, int c, size_t len);
char			**ft_free(char **str, int size);
//GET_NEXT_LINE && SPLIT && ATOI
char			*get_next_line(int fd);
char			**ft_split(char const *s, char c);
long			ft_atoi(char *str);
//PARSING
int				process_texture(t_cub3d_data *cub, char *line, int key, int i);
int				map_parsing(t_cub3d_data *cub, int ac, char **av);
int				resizematrice(t_cub3d_data *cub, int num_lines);
int				cub_file(char *s);
int				check_space(char str);
int				check_retline(t_cub3d_data *cub);
int				empty_line(t_cub3d_data *cub);
//ERROR
int				ft_error(char *s);
//INIT
double			normalizeangle(double angle);
int				init_data(t_cub3d_data *cub);
void			init_ray_data(t_cub3d_data *cub);
void			ft_mlx_init(t_cub3d_data *cub);
//VALID_COLOR
t_map_color		*valide_color(char *str);
//VALID_MAP
int				check_map(t_cub3d_data *cub, int i);
int				valid_char(t_cub3d_data *cub, char c, int i, int j);
void			put_player(t_cub3d_data *cub);
void			ft_update(t_cub3d_data *cub);
void			cub_img(t_cub3d_data *cub);
void			init_data_player(t_cub3d_data *cub);
void			ft_hook(void	*param);
void			cast_allrays(t_cub3d_data *cub);
void			ray_cast(t_cub3d_data *cub);
//HOOK
void			ft_hook(void *param);
//RAYCASTING
int				protect_matrice(double touchX, double touchY, \
				t_cub3d_data *cub);
double			distance_between_points(double x1, double y1, \
				double x2, double y2);
void			raycasting_init(t_cub3d_data *cub);
void			calcs_vertintercept(t_cub3d_data *cub);
void			calcs_horintercept(t_cub3d_data *cub);
//render
void			renderwallproject(t_cub3d_data *cub, int i);
void			read_image_colors(t_cub3d_data *cub);
int				get_color(int r, int g, int b, int a);
void			init_texture(t_cub3d_data *cub);
void			sky_floor(t_cub3d_data *cub, int x, int y);
int				distance(int i, int j, int x, int y);
void			walk_direction(t_cub3d_data *cub, int flag);
void			side_direction(t_cub3d_data *cub, int flag);
void			ft_tur_direction(t_cub3d_data *cub);
unsigned int	*get_dir(t_cub3d_data *cub);
int				check_sides(t_cub3d_data *cub, int i, int j);
#endif
