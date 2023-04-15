# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hmohamed <hmohamed@student.42abudhabi.ae>  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/23 23:48:21 by hmohamed          #+#    #+#              #
#    Updated: 2023/04/16 01:41:14 by hmohamed         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell
SRC = ms_main.c 				\
			ms_builtins.c 		\
			pars/helper_utils.c		\
			pars/free_utils.c		\
			pars/pipes.c			\
			pars/errors.c			\
			pars/rdr.c				\
			pars/expantion_utils.c	\
			tmp_printers.c			\
			ms_excute.c				\
			ms_init_exc.c			\
			lists/ft_lstnew.c		\
			lists/ft_lstsize.c		\
			lists/ft_lstlast.c		\
			lists/ft_lstadd_back.c	\
			lists/ft_lstadd_front.c	\
			lists/ft_lstdelone.c 	\
			lists/ft_lstclear.c		 \
			ms_export.c				\
			ms_exportex.c			\
			ms_unset.c 				\
			ms_others.c 			\
			ms_pipes.c 				\
			ms_pipes2.c 			\
			ms_redir.c 				\
			ms_redir2.c 			\
			ms_utils.c 				\
			ms_heredoc.c 			\
			
OBJ = $(SRC:.c=.o)
CC = cc 
CFLAGS = -g -Wall -Wextra -Werror #-fsanitize=address
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