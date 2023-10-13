NAME = Cub3D

BNAME = Cub3D_B

FLAGS = -Wall -Wextra -Werror -Ofast

CC = cc

OBJ_DIR = .obj

B_OBJ_DIR = .b_obj

SRC = Cub3D_mandatory/source/cube.c\
		Cub3D_mandatory/source/parsing/param_check.c\
		Cub3D_mandatory/source/parsing/param_value_check.c\
		Cub3D_mandatory/source/parsing/map_check.c\
		Cub3D_mandatory/source/initialisation/init_vals_parsing.c\
		Cub3D_mandatory/source/initialisation/init_val.c\
		Cub3D_mandatory/source/initialisation/start_game.c\
		Cub3D_mandatory/source/raycasting/ray_casting.c\
		Cub3D_mandatory/source/raycasting/movement.c\
		Cub3D_mandatory/source/raycasting/key_hooks.c\
		Cub3D_mandatory/source/raycasting/intersections.c\
		Cub3D_mandatory/source/draw_paint/drawing.c\
		Cub3D_mandatory/source/draw_paint/game_component.c\
		Cub3D_mandatory/source/draw_paint/painting.c\
		Cub3D_mandatory/utils/parsing_utils.c\
		Cub3D_mandatory/utils/parsing_utils1.c\
		Cub3D_mandatory/utils/cube_utils.c\
		Cub3D_mandatory/utils/mlx_helping_tools.c\
		Cub3D_mandatory/utils/libft/ft_atoi.c\
		Cub3D_mandatory/utils/libft/ft_split.c\
		Cub3D_mandatory/utils/libft/ft_strdup.c\
		Cub3D_mandatory/utils/libft/ft_strjoin.c\
		Cub3D_mandatory/utils/libft/ft_strlcpy.c\
		Cub3D_mandatory/utils/libft/ft_strlen.c\
		Cub3D_mandatory/utils/libft/ft_strjoin_gnl.c\
		Cub3D_mandatory/utils/libft/ft_substr.c\
		Cub3D_mandatory/utils/libft/ft_strcmp.c\
		Cub3D_mandatory/utils/libft/ft_isdigit.c\
		Cub3D_mandatory/utils/libft/ft_strchr.c\
		Cub3D_mandatory/utils/get_next_line/get_next_line.c\

B_SRC = Cub3D_bonus/source/cube.c\
		Cub3D_bonus/source/initialisation/start_game.c\
		Cub3D_bonus/source/draw_paint/drawing.c\
		Cub3D_bonus/source/raycasting/movement.c\
		Cub3D_bonus/source/raycasting/key_hooks.c\
		Cub3D_bonus/source/raycasting/ray_casting.c\
		Cub3D_bonus/source/raycasting/intersections.c\
		Cub3D_bonus/source/draw_paint/game_component.c\
		Cub3D_bonus/source/parsing/param_check.c\
		Cub3D_bonus/source/parsing/param_value_check.c\
		Cub3D_bonus/source/raycasting/mouse_mov.c\
		Cub3D_bonus/source/initialisation/init_val.c\
		Cub3D_bonus/source/draw_paint/painting.c\
		Cub3D_bonus/source/parsing/map_check.c\
		Cub3D_bonus/source/initialisation/init_vals_parsing.c\
		Cub3D_bonus/source/draw_paint/mini_map.c\
		Cub3D_bonus/utils/parsing_utils.c\
		Cub3D_bonus/utils/parsing_utils1.c\
		Cub3D_bonus/utils/cube_utils.c\
		Cub3D_bonus/utils/mlx_helping_tools.c\
		Cub3D_bonus/utils/libft/ft_atoi.c\
		Cub3D_bonus/utils/libft/ft_split.c\
		Cub3D_bonus/utils/libft/ft_strdup.c\
		Cub3D_bonus/utils/libft/ft_strjoin.c\
		Cub3D_bonus/utils/libft/ft_strlcpy.c\
		Cub3D_bonus/utils/libft/ft_strlen.c\
		Cub3D_bonus/utils/libft/ft_strjoin_gnl.c\
		Cub3D_bonus/utils/libft/ft_substr.c\
		Cub3D_bonus/utils/libft/ft_strcmp.c\
		Cub3D_bonus/utils/libft/ft_isdigit.c\
		Cub3D_bonus/utils/libft/ft_strchr.c\
		Cub3D_bonus/utils/get_next_line/get_next_line.c\

INC = Cub3D_mandatory/include/cube.h Cub3D_mandatory/include/get_next_line.h Cub3D_mandatory/include/libft.h

B_INC = Cub3D_bonus/include/cube.h Cub3D_bonus/include/get_next_line.h Cub3D_bonus/include/libft.h

OBJ = $(addprefix $(OBJ_DIR)/, $(SRC:.c=.o))

B_OBJ = $(addprefix $(B_OBJ_DIR)/, $(B_SRC:.c=.o))

all: $(NAME)

bonus: $(BNAME)

$(NAME): $(OBJ)
	@$(CC) $(FLAGS) $(OBJ) -lmlx -framework OpenGL -framework AppKit -o $(NAME)

$(BNAME): $(B_OBJ)
	@$(CC) $(FLAGS) $(B_OBJ) -lmlx -framework OpenGL -framework AppKit -o $(BNAME)

$(OBJ_DIR)/%.o: %.c $(INC)
	@mkdir -p $(dir $@)
	@$(CC) $(FLAGS) -Imlx -c $< -o $@

$(B_OBJ_DIR)/%.o: %.c $(B_INC)
	@mkdir -p $(dir $@)
	@$(CC) $(FLAGS) -Imlx -c $< -o $@

clean:
	@rm -rf $(OBJ_DIR) $(OBJ) $(B_OBJ_DIR) $(B_OBJ)

fclean: clean
	@rm -f $(NAME) $(BNAME)

re: fclean all

run: all
	@./cube3d

.PHONY: all re fclean clean
