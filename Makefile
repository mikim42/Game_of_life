# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mikim <mikim@student.42.us.org>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/04/03 20:55:24 by mikim             #+#    #+#              #
#    Updated: 2017/10/20 20:45:05 by mikim            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = main.c\
	  parse.c\
	  game_of_life.c\
	  print_handler.c\
	  slist_handler.c\
	  rule_handler.c

OBJ = $(SRC:.c=.o)
MLX = -L $(MLXDIR) -lmlx -framework OpenGL -framework Appkit

SRCDIR = srcs
OBJDIR = objs
LIBDIR = libs/libft
MLXDIR = libs/mlx

SRCS = $(addprefix $(SRCDIR)/, $(SRC))
OBJS = $(addprefix $(OBJDIR)/, $(OBJ))
LIBS = $(LIBDIR)/libft.a $(MLX)
HEADER = -I includes -I $(LIBDIR)/includes -I $(MLXDIR)

CC = gcc
CFLAGS = -c -Wall -Wextra -Werror

NAME = game_of_life

.PHONY: all clean fclean re
.SUFFIXES: .c .o

all: $(NAME)

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	@mkdir -p $(OBJDIR)
	@$(CC) $(CFLAGS) -I includes -I $(LIBDIR)/includes -I $(MLXDIR) $< -o $@

$(NAME): $(OBJS)
	@make -C $(MLXDIR)
	@make -C $(LIBDIR)
	@$(CC) $(OBJS) $(LIBS) -o $@
	@echo "[Game_of_Life - 모래반지 빵야빵야!]"

clean:
	@/bin/rm -rf $(OBJDIR)
	@make -C $(MLXDIR) clean
	@make -C $(LIBDIR) clean

fclean: clean
	@/bin/rm -f $(NAME)
	@rm -f $(LIBDIR)/libft.a
	@echo "[Game_of_Life - fclean]"

re: fclean all
