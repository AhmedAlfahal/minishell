# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aalfahal <aalfahal@student.42abudhabi.ae>  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/26 05:25:53 by aalfahal          #+#    #+#              #
#    Updated: 2023/04/30 16:51:32 by aalfahal         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	minishell

CC			=	cc

READLINE	=	-lreadline -I/usr/local/opt/readline/include -L/usr/local/opt/readline/lib

CFLAGS		=	-Wall -Wextra -Werror

LIBFT		=	./libft/libft.a

SRC			=	main.c 					\
				pars/helper_utils.c		\
				pars/free_utils.c		\
				pars/pipes.c			\
				pars/errors.c			\
				pars/rdr.c				\
				pars/expantion_utils.c	\
				lists/ft_lstnew.c		\
				lists/ft_lstsize.c		\
				lists/ft_lstlast.c		\
				lists/ft_lstadd_back.c	\
				lists/ft_lstadd_front.c	\
				lists/ft_lstdelone.c 	\
				lists/ft_lstclear.c		\
				exec/ms_excute.c		\
				exec/ms_init_exc.c		\
				exec/ms_builtins.c 		\
				exec/ms_export.c		\
				exec/ms_exportex.c		\
				exec/ms_unset.c 		\
				exec/ms_others.c 		\
				exec/ms_pipes.c 		\
				exec/ms_pipes2.c 		\
				exec/ms_redir.c 		\
				exec/ms_redir2.c 		\
				exec/ms_utils.c 		\
				exec/ms_heredoc.c 		\
				exec/ms_hdoc2.c 
			
OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME) : $(OBJ)
	@make -C ./libft
	$(CC) $(CFLAGS) $(OBJ) $(READLINE) $(LIBFT) -o $(NAME) 

clean:
	make clean -C ./libft
	rm -fr $(OBJ)

fclean: clean
		make fclean -C ./libft
		rm -f minishell
		
re: fclean all
