CC := cc
NAME := cub3D
INC := mandatory/includes/cub3d.h mandatory/includes/macros.h
INC_B := bonus/includes/cub3d.h bonus/includes/macros.h
B_NAME := cub3D_b
CFLAGS := -Wall -Wextra -Werror
SRCS =	mandatory/src/main.c mandatory/src/utilis/gnl.c mandatory/src/utilis/utils.c mandatory/src/utilis/ft_split.c mandatory/src/utilis/ft_atoi.c mandatory/src/raycasting/raycasting_utils1.c mandatory/src/raycasting/raycastingutils2.c mandatory/src/utilis/utils_2.c\
			mandatory/src/parsing/parsing.c mandatory/src/parsing/errors.c mandatory/src/parsing/valide_color.c mandatory/src/parsing/valide_file.c mandatory/src/parsing/valide_map.c mandatory/src/raycasting/raycasting.c \
			mandatory/src/init/init.c  mandatory/src/minimap.c mandatory/src/utilis/keyhook.c mandatory/src/utilis/keyhookutil.c mandatory/src/init/sky_floor.c mandatory/src/utilis/texture_utils.c \

BONUS =	bonus/src/main.c bonus/src/utilis/gnl.c bonus/src/utilis/utils.c bonus/src/utilis/ft_split.c bonus/src/render/sprite_utils2.c bonus/src/utilis/ft_atoi.c bonus/src/raycasting/raycasting_utils.c bonus/src/utilis/utils_2.c bonus/src/render/sprite_utils.c\
			bonus/src/parsing/parsing.c bonus/src/parsing/errors.c bonus/src/parsing/valide_color.c bonus/src/parsing/valide_file.c bonus/src/parsing/valide_map.c bonus/src/raycasting/raycasting.c bonus/src/render/render_wall.c\
			bonus/src/init/init.c  bonus/src/minimap.c bonus/src/init/init_util.c bonus/src/minimap_util.c bonus/src/utilis/keyhook.c bonus/src/utilis/keyhook_util2.c bonus/src/init/sky_floor.c bonus/src/init/fullmap.c bonus/src/init/fullmaputils.c \
			bonus/src/utilis/texture_utils.c bonus/src/render/sprites.c bonus/draw_line.c bonus/src/utilis/keyhookutil.c bonus/src/utilis/keyhook_util3.c

B_OBJ = $(BONUS:.c=.o)
MLX        := mandatory/libs/libmlx.a
LIBS    := -lglfw -L/Users/lsabik/.brew/opt/glfw/lib
# LIBS    := -lglfw -L/Users/nouahidi/.brew/opt/glfw/lib

OBJS := $(SRCS:.c=.o)

all: $(NAME)

bonus: $(B_NAME)

%.o: %.c $(INC) $(INC_B)
	$(CC) $(CFLAGS) -c $< -o $@


$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(MLX) ${LIBFT} -o $(NAME) $(LIBS)

$(B_NAME): $(B_OBJ)
	$(CC) $(CFLAGS) $(B_OBJ) $(MLX) ${LIBFT} -o $(B_NAME) $(LIBS)

clean:
	rm -f $(OBJS) $(B_OBJ)

fclean: clean
	rm -f $(NAME) $(B_NAME)

re: fclean all bonus
