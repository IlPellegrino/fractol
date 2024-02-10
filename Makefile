# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nromito <nromito@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/10 18:48:26 by nromito           #+#    #+#              #
#    Updated: 2024/01/31 14:53:41 by nromito          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol
SRCS = fract-ol.c formulas.c pixels.c close.c events.c

OBJS = ${SRCS:.c=.o}

MLX_PATH = mlx/
MLX_A = libmlx.a
MLX = $(addprefix $(MLX_PATH), $(MLX_A))

MLX_INCLUDE = -lXext -lX11 -lm

LIBFT_PATH = libft/
LIBFT = libft/libft.a

NONE = '\033[0m'
GREEN = '\033[32m'

COMPILE = cc -Wall -Wextra -Werror -g

all: ${NAME}

${NAME}: ${OBJS}
	make -C $(MLX_PATH)
	make -C $(LIBFT_PATH)
	$(COMPILE) $(OBJS) $(MLX) $(LIBFT) $(MLX_INCLUDE) -o $(NAME)
	@echo $(GREEN) "Successfully compiled!" $(NONE)
	
$(OBJS): $(SRCS) lib.h
	$(COMPILE) -c $(SRCS)

clean:
	@rm -rf $(OBJS)
	@make -C $(LIBFT_PATH)	
	@make -C $(MLX_PATH)

fclean: clean
	@rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean