# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aalfahal <aalfahal@student.42abudhabi.ae>  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/26 05:25:53 by aalfahal          #+#    #+#              #
#    Updated: 2023/03/28 23:44:41 by aalfahal         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CFLAGS	=	-Wall -Wextra -Werror -g3 #-fsanitize=address

NAME	=	minishell

LIBFT	=	libft/libft.a

SRC		=	minishell.c			\
			counters_dupper.c	\
			free_utils.c				\
			pars_utils.c		\
			pipes.c

SRCS	=	$(SRC:%.c=%.o)

all : $(NAME)

$(NAME) : $(SRCS)
	make -C ./libft
	$(CC) $(CFLAGS) $(SRCS) -L/usr/local/lib -I/usr/local/include -lreadline $(LIBFT) -o $(NAME)

clean:
	make clean -C ./libft
	rm -fr $(SRCS)

fclean: clean
	make fclean -C ./libft
	rm -fr $(NAME)

re: fclean all