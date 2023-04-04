# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aalfahal <aalfahal@student.42abudhabi.ae>  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/26 05:25:53 by aalfahal          #+#    #+#              #
#    Updated: 2023/04/05 01:12:03 by aalfahal         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CFLAGS	=	-Wall -Wextra -Werror -g3 #-fsanitize=address

NAME	=	minishell

LIBFT	=	libft/libft.a

SRC		=	pars/minishell.c		\
			pars/helper_utils.c		\
			pars/free_utils.c		\
			pars/pipes.c			\
			pars/rdr_errors.c		\
			pars/rdr.c				\
			tmp_printers.c

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