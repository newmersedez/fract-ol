# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lorphan <lorphan@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/09/16 16:52:01 by lorphan           #+#    #+#              #
#    Updated: 2021/10/05 15:19:57 by lorphan          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			= fractol
LIBFT			= ./libft/libft.h

CC				= gcc
CFLAGS			= -Wall -Wextra -Werror
RM				= rm -rf

INCLUDES_DIR	= ./includes/
SOURCES_DIR		= ./sources/ ./sources/controls/ ./sources/drawing/ ./sources/math/ ./sources/utils/
OBJECTS_DIR		= ./objects/
LIBFT_DIR		= ./libft/

INCLUDES		= $(wildcard $(addsuffix *.h, $(INCLUDES_DIR)))
SOURCES			= $(wildcard $(addsuffix *.c, $(SOURCES_DIR)))
OBJECTS			= $(addprefix $(OBJECTS_DIR), $(notdir $(patsubst %.c, %.o, $(SOURCES))))

VPATH = $(SOURCES_DIR)

$(OBJECTS_DIR)%.o: %.c $(INCLUDES)
					mkdir -p $(OBJECTS_DIR)
					$(CC) $(CFLAGS) -Imlx  -c $< -o $@

all:				$(LIBFT) $(NAME)

$(NAME):			$(INCLUDES)  $(OBJECTS)
					make -C $(LIBFT_DIR)
					$(CC) $(CFLAGS) $(OBJECTS) ./libft/libft.a -lmlx -framework OpenGL -framework AppKit -o $(NAME)

clean:
					$(RM) $(OBJECTS_DIR)
					make clean -C $(LIBFT_DIR)

fclean:				clean
					$(RM) $(NAME)
					make fclean -C $(LIBFT_DIR)

bonus:				all

re:					fclean all
