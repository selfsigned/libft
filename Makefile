# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: xperrin <xperrin@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/10/04 19:33:10 by xperrin           #+#    #+#              #
#    Updated: 2017/11/17 21:04:50 by xperrin          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
SONAME = $(NAME:.a=.so)
CC = gcc
CFLAGS = -Wall -Wextra -Werror -I.

FT_LIBC = ft_memset.c ft_bzero.c ft_memcpy.c ft_memccpy.c ft_memmove.c \
	ft_memchr.c ft_memcmp.c \
	ft_strlen.c ft_strdup.c ft_strcpy.c ft_strncpy.c \
	ft_strcat.c ft_strncat.c ft_strlcat.c ft_strchr.c ft_strrchr.c \
	ft_strstr.c ft_strnstr.c ft_strcmp.c ft_strncmp.c \
	ft_atoi.c ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c \
	ft_isprint.c ft_toupper.c ft_tolower.c
FT_42 = ft_memalloc.c ft_memdel.c ft_strnew.c ft_strdel.c ft_strclr.c \
	ft_striter.c ft_strmap.c ft_itoa.c \
	ft_putchar.c ft_putstr.c ft_putendl.c ft_putnbr.c \
	ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c
SRC = $(FT_LIBC) $(FT_42)
OBJ = $(SRC:.c=.o)

.PHONY: all so clean fclean re

all: $(NAME)

$(NAME): $(OBJ)
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)

$(SONAME): CFLAGS += -fPIC
$(SONAME): $(OBJ)
	 $(CC) -shared -o $(SONAME) $(OBJ)

so: $(SONAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME) $(SONAME)

re: fclean all
