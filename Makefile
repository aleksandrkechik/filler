# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hturkatr <hturkatr@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/12/01 11:38:05 by hturkatr          #+#    #+#              #
#    Updated: 2019/12/01 14:27:12 by hturkatr         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

COLOR_NONE = \e[0m
COLOR_WHITE = \e[1;37m
COLOR_BLUE = \e[1;34m
COLOR_GREEN = \e[1;32m
COLOR_PURPLE = \e[1;35m

NAME = hturkatr.filler
CCFL = gcc -Wall -Wextra -Werror
SRC_PATH = ./src/
SRCS = src/main.c src/gnl.c src/heatmap.c src/piece.c src/player.c src/cell.c src/heatmap2.c src/piece2.c src/piece3.c src/visualiser.c src/field.c src/player_alg.c src/field2.c
OBJ = $(patsubst %.c,%.o,$(SRCS))
INCL = -Iincludes -Ilibft -Iminilibx_macos
FRAMEWORKS = -framework OpenGL -framework AppKit
LIBRARIES = -lftprintf -lmlx -lm -L$(LIBFT_DIR) -L$(MINILIBX_DIR)
MINILIBX_DIR = ./minilibx_macos
MINILIBX_PATH = $(MINILIBX_DIR)/libmlx.a
LIBFT_DIR = ./printflib
LIBFT_PATH = $(LIBFT_DIR)/libprintf.a

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(MINILIBX_PATH) $(LIBFT_PATH) $(OBJ)
	@printf "$(COLOR_GREEN)Linking objects together...$(COLOR_NONE)\n"
	@$(CCFL) $(LIBRARIES) $(INCL) $(FRAMEWORKS) $(OBJ)
	@mv ./a.out $(NAME)

%.o: %.c
	@printf "$(COLOR_GREEN)Compiling $(COLOR_PURPLE)$<$(COLOR_GREEN) to $(COLOR_PURPLE)$@$(COLOR_GREEN)...$(COLOR_NONE)\n"
	@$(CCFL) $(INCL) $< -c -o $@

clean:
	@printf "$(COLOR_GREEN)Cleaning object files...$(COLOR_NONE)\n"
	@/bin/rm -f $(OBJ)
	@$(MAKE) -C $(MINILIBX_DIR) clean
	@$(MAKE) -C $(LIBFT_DIR) clean

$(MINILIBX_PATH):
	@printf "$(COLOR_GREEN)Compiling minilibx...$(COLOR_NONE)\n"
	@$(MAKE) -C $(MINILIBX_DIR)

$(LIBFT_PATH):
	@printf "$(COLOR_GREEN)Compiling libprintf...$(COLOR_NONE)\n"
	@$(MAKE) -C $(LIBFT_DIR)

fclean: clean
	@printf "$(COLOR_GREEN)Cleaning executable...$(COLOR_NONE)\n"
	@/bin/rm -f $(NAME)
	@/bin/rm -f $(MINILIBX_PATH)
	@$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean $(NAME)