# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aalfahal <aalfahal@student.42abudhabi.ae>  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/01 23:54:55 by aalfahal          #+#    #+#              #
#    Updated: 2023/01/22 20:33:46 by aalfahal         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= libft.a

CC		= cc

CFLAGS	= -Wall -Wextra -Werror

OBJ		= 	ft_isascii.c	\
			ft_memcpy.c		\
			ft_strdup.c		\
			ft_strnstr.c	\
			ft_bzero.c		\
			ft_isdigit.c	\
			ft_strlcat.c	\
			ft_strrchr.c	\
			ft_calloc.c		\
			ft_isprint.c	\
			ft_memset.c		\
			ft_strlcpy.c	\
			ft_tolower.c	\
			ft_isalnum.c	\
			ft_memchr.c		\
			ft_memmove.c	\
			ft_strlen.c		\
			ft_toupper.c	\
			ft_isalpha.c 	\
			ft_memcmp.c 	\
			ft_strchr.c 	\
			ft_strncmp.c	\
			ft_atoi.c		\
			ft_strjoin.c	\
			ft_substr.c		\
			ft_strtrim.c	\
			ft_split.c		\
			ft_putstr_fd.c	\
			ft_putendl_fd.c	\
			ft_putchar_fd.c	\
			ft_putnbr_fd.c	\
			ft_itoa.c		\
			ft_strmapi.c	\
			ft_striteri.c
		

BOBJ	=	ft_lstmap.c				\
			ft_lstnew.c				\
			ft_lstsize.c			\
			ft_lstlast.c			\
			ft_lstiter.c			\
			ft_lstclear.c			\
			ft_lstdelone.c			\
			ft_lstadd_back.c		\
			ft_lstadd_front.c		\
			
OBJS 	= $(OBJ:%.c=%.o)

BOBJS 	= $(BOBJ:%.c=%.o)

all: $(NAME)

$(NAME): $(OBJS)
	ar rc $(NAME) $(OBJS)

bonus: $(BOBJS)
	ar rc $(NAME) $(BOBJS)

clean:
	rm -fr $(OBJS) $(BOBJS)

fclean: clean
	rm -fr $(NAME)

re: clean all
