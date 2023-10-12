NAME = Cub3D

FLAGS = -Wall -Wextra -Werror -Ofast

CC = cc

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
		source/start_game.c\
		source/drawing.c\
		source/movement.c\
		source/key_hooks.c\
		source/mlx_helping_tools.c\
		source/ray_casting.c\
		source/intersections.c\
		source/game_component.c\
		source/param_check.c\
		source/param_value_check.c\
		utils/parsing_utils.c\
		utils/parsing_utils1.c\
		utils/cube_utils.c\
		source/mouse_mov.c\
		source/init_val.c \
		source/painting.c \
		source/map_check.c \
		source/init_vals_parsing.c \

LIBFT_OBJ = $(LIBFT_SRC:.c=.o)

GNL_OBJ = $(GNL_SRC:.c=.o)

OBJ = $(SRC:.c=.o)

all: $(NAME)

%.o: %.c include/cube.h include/get_next_line.h include/libft.h
	@$(CC) $(FLAGS) -Imlx -c $< -o $@

$(NAME): $(OBJ) $(GNL_OBJ) $(LIBFT_OBJ)
	@$(CC) $(FLAGS) $(OBJ) $(GNL_OBJ) $(LIBFT_OBJ) -lmlx -framework OpenGL -framework AppKit -o $(NAME)

clean:
	@rm -f $(OBJ) $(GNL_OBJ) $(LIBFT_OBJ)

fclean: clean
	@rm -f $(NAME)

re: fclean all

run: all
	@./cube3d

.PHONY: all re fclean clean
