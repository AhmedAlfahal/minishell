# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aalfahal <aalfahal@student.42abudhabi.ae>  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/26 05:25:53 by aalfahal          #+#    #+#              #
#    Updated: 2023/04/14 09:20:33 by aalfahal         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CFLAGS	=	-g3 -Wall -Wextra -Werror #-fsanitize=address

NAME	=	minishell

LIBFT	=	libft/libft.a

SRC		=	pars/minishell.c		\
			pars/helper_utils.c		\
			pars/free_utils.c		\
			pars/pipes.c			\
			pars/errors.c			\
			pars/rdr.c				\
			pars/expantion_utils.c	\
			exec/ms_builtins.c		\
			exec/ms_excute.c		\
			exec/ms_export.c		\
			exec/ms_exportex.c		\
			exec/ms_init_exc.c		\
			exec/ms_others.c		\
			exec/ms_unset.c			\
			exec/ms_pipes.c			\
			exec/ms_pipes2.c		\
			exec/ms_redir.c			\
			exec/ms_redir2.c		\
			lists/ft_lstnew.c		\
			lists/ft_lstsize.c		\
			lists/ft_lstlast.c		\
			lists/ft_lstadd_back.c	\
			lists/ft_lstadd_front.c	\
			lists/ft_lstdelone.c 	\
			lists/ft_lstclear.c		\
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
