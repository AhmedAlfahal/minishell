# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hmohamed <hmohamed@student.42abudhabi.ae>  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/23 23:48:21 by hmohamed          #+#    #+#              #
#    Updated: 2023/04/01 03:10:44 by hmohamed         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell
SRC = ms_main.c 				\
			ms_builtins.c 		\
		pars/counters_dupper.c		\
			pars/free_utils.c		\
			pars/pars_utils.c		\
			pars/pipes.c			\
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
			
OBJ = $(SRC:.c=.o)
CC = cc 
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