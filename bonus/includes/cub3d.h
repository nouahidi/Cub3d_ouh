/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nouahidi <nouahidi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 22:54:53 by lsabik            #+#    #+#             */
/*   Updated: 2023/07/28 13:56:15 by nouahidi         ###   ########.fr       */
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
# include <time.h>
# include <signal.h>
# define MINIMAP_SCALE 0.3

typedef struct spinfos
{
	double	sp_height;
	double	sp_width;
	double	sp_topy;
	double	sp_bottomy;
	double	sp_angle;
	double	sp_screen_imgpos;
	double	sp_leftx;
	double	sp_rightx;
	double	texelwidth;
	double	correct_dist;
	int		text_x;
	int		text_y;
	int		dist_fromtop;
}				t_spinfos;

typedef struct sprites
{
	int				text;
	double			x;
	double			y;
	int				index;
	double			dist;
	bool			visible;
	double			angle;
	mlx_texture_t	*sp_text;
}					t_sprites;

typedef struct rays
{
	double	ray_ang;
	double	is_rayfacingdown;
	double	is_rayfacingup;
	double	is_rayfacingright;
	double	is_rayfacingleft;
	double	yintercept;
	double	xintercept;
	double	ystep;
	double	xstep;
	int		foundhorzwallhit;
	double	hor_itx;
	double	hor_wallhity;
	double	hor_wallhitx;
	int		foundverzwallhit;
	double	vert_wallhitx;
	double	vert_wallhity;
	double	hit_verti;
	double	distance;
	double	wallhit_x;
	double	wallhit_y;
	int		ver_cont;
	int		hor_cont;
	int		map_cont;
	int		flag;
}				t_ray_data;

typedef struct s_map_color
{
	int			r;
	int			g;
	int			b;
}				t_map_color;

typedef struct player_movement
{
	double	mpx;
	double	mpy;
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
	int				openflag;
	char			*line;
	int				player_x;
	int				player_y;
	char			player_dir;
	int				len_i;
	int				len_j;
	unsigned int	*texture;
	unsigned int	*walltexture[30];
	double			ray_dist[NUM_RAYS];
	int				sprite_num;
	int				beginx;
	int				beginy;
	int				mouse_x;
	int				mouse_y;
	int				lenx_fullmap;
	int				leny_fullmap;
	int				xdoor;
	int				ydoor;
	int				doorflag;
	int				tm;
	int				x_wall;
	int				y_wall;
	int				text_offsetx;
	double			d_pr_plane;
	double			pr_wallheight;
	double			tmp_px;
	int				wallstripheight;
	int				walltop;
	int				wallbottom;
	int				text_offsety;
	int				tmpi;
	int				tmp_vl;
	int				dx;
	int				dy;
	int				sx;
	int				sy;
	int				anim_flag;
	int				walk_flag;
	int				mode_fg;
	pid_t			pid;
	t_spinfos		*sp;
	t_sprites		*sprites;
	mlx_texture_t	*text[30];
	t_ray_data		*rays;
	t_map_color		*c_f;
	t_map_color		*c_c;
	mlx_image_t		*sky_floor;
	mlx_image_t		*map_img;
	mlx_image_t		*full_map;
	mlx_image_t		*minimap;
	mlx_image_t		*time;
	mlx_texture_t	*cj[17];
	mlx_image_t		*screen_img;
	mlx_image_t		*intro;
	mlx_image_t		*mode;
	t_data_player	*player;
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
void			found_door(t_cub3d_data *cub);
int				distance(int i, int j, int x, int y);
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
void			load_png(mlx_texture_t **text, char *path);
//VALID_COLOR
t_map_color		*valide_color(char *str);
//VALID_MAP
int				check_map(t_cub3d_data *cub, int i);
int				valid_char(t_cub3d_data *cub, char c, int i, int j);
void			put_player(t_cub3d_data *cub);
void			ft_update(t_cub3d_data *cub);
void			cub_img(t_cub3d_data *cub);
void			init_data_player(t_cub3d_data *cub);
void			cast_allrays(t_cub3d_data *cub);
void			ray_cast(t_cub3d_data *cub, double horz_dist, double ver_dist);
int				check_ch(t_cub3d_data *cub, int bx, int by, char c);
//HOOK
void			ft_hook(void *param);
int				hit_sprite(t_cub3d_data *cub);
void			cj_walk(t_cub3d_data *cub);
//RAYCASTING
int				protect_matrice(double touchX, double touchY, \
				t_cub3d_data *cub);
double			distance_between_points(double x1, double y1, \
				double x2, double y2);
void			raycasting_init(t_cub3d_data *cub);
void			calcs_vertintercept(t_cub3d_data *cub);
void			calcs_horintercept(t_cub3d_data *cub);
void			vert_intersec(t_cub3d_data *cub);
void			hor_intersec(t_cub3d_data *cub);
//render
void			renderwallproject(t_cub3d_data *cub, int i, int x);
void			read_image_colors(t_cub3d_data *cub);
int				get_color(int r, int g, int b, int a);
void			read_color(t_cub3d_data *cub);
void			sky_floor(t_cub3d_data *cub, int x, int y);
int				distance(int i, int j, int x, int y);
void			put_mini_map(t_cub3d_data *cub);
void			ft_put_minimap(t_cub3d_data *cub);
void			drawline(t_cub3d_data *cub, int x2, int y2);
void			setting_map(t_cub3d_data *cub);
//sound
void			add_sounds(t_cub3d_data *cub, int sound);
//SPRITES
void			render_sprite(t_cub3d_data *cub, int index);
void			render_mapsprites(t_cub3d_data *cub);
void			find_sprites(t_cub3d_data *cub, int i, int j, int n);
void			add_door(t_cub3d_data *cub, char c1, char c2);
void			ft_tur_direction(t_cub3d_data *cub);
void			walk_direction(t_cub3d_data *cub, int flag);
void			side_direction(t_cub3d_data *cub, int flag);
void			ft_door(t_cub3d_data *cub);
int				index_dir(t_cub3d_data *cub);
void			draw_fullmap(t_cub3d_data *cub);
void			png_info(t_cub3d_data *cub, int num, mlx_texture_t *text);
void			calc_sprite_dims(t_cub3d_data *cub, t_sprites sprite);
void			sort_by_distance(t_sprites *vis_sprites, int vis_sp);
void			draw_sprites(t_cub3d_data *cub, t_sprites *vis_sprites, \
				int vis_sp);
void			fixed_sprites(t_cub3d_data *cub, int i, int j, int k);
void			render_vis_sprites(t_cub3d_data *cub, t_sprites *vis_sprites, \
				int vis_sp);
void			calcs_offset_y(t_cub3d_data *cub, \
int y, mlx_texture_t *sp_text);
void			calcs_offset_x(t_cub3d_data *cub, \
int x, mlx_texture_t *sp_text);
void			sprites_animation(t_cub3d_data *cub);
void			norm_angle(double *angle);
void			display_current_time(t_cub3d_data *cub);
int				sprites_char(char c);
void			init_img(t_cub3d_data *cub);
void			ft_load_png(t_cub3d_data *cub);
void			free_all(t_cub3d_data *cub);
int				empty_line(t_cub3d_data *cub);
int				check_sides(t_cub3d_data *cub, int i, int j);
#endif
