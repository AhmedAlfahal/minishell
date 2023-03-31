# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hmohamed <hmohamed@student.42abudhabi.ae>  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/23 23:48:21 by hmohamed          #+#    #+#              #
#    Updated: 2023/03/31 21:40:46 by hmohamed         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell
SRC = ms_main.c ms_builtins.c \
		pars/counters_dupper.c	\
			pars/free_utils.c		\
			pars/pars_utils.c		\
			pars/pipes.c			\
			tmp_printers.c			\
			ms_excute.c
			
OBJ = $(SRC:.c=.o)
CC = gcc
CFLAGS = -g -fsanitize=address -Wall -Wextra -Werror
LIBFT = ./libft/libft.a

all: $(NAME)

$(NAME) : $(OBJ)
	make -C libft/
	$(CC) $(CFLAGS) $(OBJ) -L/usr/local/lib -I/usr/local/include -lreadline $(LIBFT) -o $(NAME) 

clean:
		rm -f *.o */*.o
		make fclean -C \libft

fclean: clean
		rm -f minishell
		make fclean -C \libft
		
re: fclean all