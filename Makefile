# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hmohamed <hmohamed@student.42abudhabi.ae>  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/23 23:48:21 by hmohamed          #+#    #+#              #
#    Updated: 2023/03/27 22:38:20 by hmohamed         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell
SRC = ms_main.c 
OBJ = $(SRC:.c=.o)
CC = gcc
CFLAGS = -g -Wall -Wextra -Werror
LIBFT = ./libft/libft.a

all: $(NAME)

$(NAME) : $(OBJ)
	make -C libft/
	$(CC) $(CFLAGS) $(OBJ) $(LIBFT) -o $(NAME) 

clean:
		rm -f *.o
		make fclean -C \libft

fclean: clean
		rm -f minishell
		make fclean -C \libft
		
re: fclean all