# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hmohamed <hmohamed@student.42abudhabi.ae>  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/23 23:48:21 by hmohamed          #+#    #+#              #
#    Updated: 2023/04/29 13:00:35 by hmohamed         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell
SRC = exec/ms_main.c 				\
			pars/helper_utils.c		\
			pars/free_utils.c		\
			pars/pipes.c			\
			pars/errors.c			\
			pars/rdr.c				\
			pars/expantion_utils.c	\
			tmp_printers.c			\
			lists/ft_lstnew.c		\
			lists/ft_lstsize.c		\
			lists/ft_lstlast.c		\
			lists/ft_lstadd_back.c	\
			lists/ft_lstadd_front.c	\
			lists/ft_lstdelone.c 	\
			lists/ft_lstclear.c		 \
			exec/ms_excute.c				\
			exec/ms_init_exc.c			\
			exec/ms_builtins.c 		\
			exec/ms_export.c				\
			exec/ms_exportex.c			\
			exec/ms_unset.c 				\
			exec/ms_others.c 			\
			exec/ms_pipes.c 				\
			exec/ms_pipes2.c 			\
			exec/ms_redir.c 				\
			exec/ms_redir2.c 			\
			exec/ms_utils.c 				\
			exec/ms_heredoc.c 			\
			exec/ms_hdoc2.c 				\
			
OBJ = $(SRC:.c=.o)
CC = cc 
CFLAGS = -g -Wall -Wextra -Werror #-fsanitize=address
LIBFT = ./libft/libft.a

all: $(NAME)

$(NAME) : $(OBJ)
	make -C libft/
	$(CC) $(CFLAGS) $(OBJ) -lreadline -I/usr/local/opt/readline/include -L/usr/local/opt/readline/lib $(LIBFT) -o $(NAME) 

clean:
		rm -f *.o */*.o
		make fclean -C \libft

fclean: clean
		rm -f minishell
		make fclean -C \libft
		
re: fclean all