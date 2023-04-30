# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aalfahal <aalfahal@student.42abudhabi.ae>  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/01 23:54:55 by aalfahal          #+#    #+#              #
#    Updated: 2023/04/30 17:13:36 by aalfahal         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= libft.a

CC		= cc

CFLAGS	= -Wall -Wextra -Werror

OBJ		= 	ft_strdup.c		\
			ft_isdigit.c	\
			ft_bzero.c		\
			ft_isexpan.c	\
			ft_tolower.c	\
			ft_strlen.c		\
			ft_strchr.c 	\
			ft_strncmp.c	\
			ft_isrdr.c		\
			ft_strjoin.c	\
			ft_substr.c		\
			ft_strtrim.c	\
			ft_split.c		\
			ft_putstr_fd.c	\
			ft_itoa.c		\
			ft_isalpha.c 	\
			ft_atol.c 		

OBJS 	= $(OBJ:%.c=%.o)

all: $(NAME)

$(NAME): $(OBJS)
	ar rc $(NAME) $(OBJS)

clean:
	rm -fr $(OBJS)

fclean: clean
	rm -fr $(NAME)

re: clean all
