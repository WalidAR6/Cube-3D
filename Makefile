NAME = cube3d

FLAGS = -Wall -Wextra -Werror

CC = cc

LIBFT_SRC = utils/libft/ft_atoi.c\
			utils/libft/ft_split.c\
			utils/libft/ft_strdup.c\
			utils/libft/ft_strjoin.c\
			utils/libft/ft_strlcpy.c\
			utils/libft/ft_strlen.c\
			utils/libft/ft_strjoin_gnl.c\
			utils/libft/ft_substr.c

GNL_SRC = utils/get_next_line/get_next_line.c

SRC = src/cube.c\
		src/start_game.c\
		src/drawing.c\
		src/movement.c\
		src/key_hooks.c\
		src/mlx_helping_tools.c\
		src/init_val.c

LIBFT_OBJ = $(LIBFT_SRC:.c=.o)

GNL_OBJ = $(GNL_SRC:.c=.o)

OBJ = $(SRC:.c=.o)

all: $(NAME)

%.o: %.c inc/cube.h inc/get_next_line.h inc/libft.h
	$(CC) $(FLAGS) -Imlx -c $< -o $@

$(NAME): $(OBJ) $(GNL_OBJ) $(LIBFT_OBJ)
	$(CC) $(FLAGS) $(OBJ) $(GNL_OBJ) $(LIBFT_OBJ) -lmlx -framework OpenGL -framework AppKit -o $(NAME)

clean:
	rm -f $(OBJ) $(GNL_OBJ) $(LIBFT_OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all re fclean clean
