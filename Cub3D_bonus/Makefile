NAME = Cub3D_Bonus

FLAGS = -Wall -Wextra -Werror -Ofast

CC = cc

OBJ_DIR = .obj

LIBFT_SRC = utils/libft/ft_atoi.c\
			utils/libft/ft_split.c\
			utils/libft/ft_strdup.c\
			utils/libft/ft_strjoin.c\
			utils/libft/ft_strlcpy.c\
			utils/libft/ft_strlen.c\
			utils/libft/ft_strjoin_gnl.c\
			utils/libft/ft_substr.c\
			utils/libft/ft_strcmp.c\
			utils/libft/ft_isdigit.c 

GNL_SRC = utils/get_next_line/get_next_line.c

SRC = source/cube.c\
		source/initialisation/start_game.c\
		source/draw_paint/drawing.c\
		source/raycasting/movement.c\
		source/raycasting/key_hooks.c\
		source/raycasting/ray_casting.c\
		source/raycasting/intersections.c\
		source/draw_paint/game_component.c\
		source/parsing/param_check.c\
		source/parsing/param_value_check.c\
		source/raycasting/mouse_mov.c\
		source/initialisation/init_val.c \
		source/draw_paint/painting.c \
		source/parsing/map_check.c \
		source/initialisation/init_vals_parsing.c \
		source/draw_paint/mini_map.c \
		utils/parsing_utils.c\
		utils/parsing_utils1.c\
		utils/cube_utils.c\
		utils/mlx_helping_tools.c\

LIBFT_OBJ = $(LIBFT_SRC:.c=.o)

GNL_OBJ =  $(GNL_SRC:.c=.o)

OBJ = $(addprefix $(OBJ_DIR)/, $(SRC:.c=.o))

all: $(NAME)

$(NAME): $(OBJ) $(GNL_OBJ) $(LIBFT_OBJ)
	@$(CC) $(FLAGS) $(OBJ) $(GNL_OBJ) $(LIBFT_OBJ) -lmlx -framework OpenGL -framework AppKit -o $(NAME)

$(OBJ_DIR)/%.o: %.c include/cube.h include/get_next_line.h include/libft.h
	@mkdir -p $(dir $@)
	@$(CC) $(FLAGS) -Imlx -c $< -o $@

clean:
	@rm -rf $(OBJ_DIR) $(OBJ) $(GNL_OBJ) $(LIBFT_OBJ)

fclean: clean
	@rm -f $(NAME)

re: fclean all

run: all
	@./cube3d

.PHONY: all re fclean clean
