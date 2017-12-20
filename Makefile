# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: xperrin <xperrin@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/10/04 19:33:10 by xperrin           #+#    #+#              #
#    Updated: 2017/12/20 17:13:45 by xperrin          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
SONAME = $(NAME:.a=.so)
CC = clang
CFLAGS = -Wall -Wextra -Werror
INCDIR = includes
INCFILES = libft.h
INCFULL = $(addprefix $(INCDIR)/, $(INCFILES))
INC = $(addprefix -I, $(INCDIR))

# Source Files
MEMDIR = src/memory
FT_MEM = ft_memset.c ft_bzero.c ft_memcpy.c ft_memccpy.c ft_memmove.c \
	ft_memchr.c ft_memcmp.c ft_memalloc.c ft_memdel.c

STRDIR = src/string
FT_STR = ft_strlen.c ft_strdup.c ft_strcpy.c ft_strncpy.c \
	ft_strcat.c ft_strncat.c ft_strlcat.c ft_strchr.c ft_strrchr.c \
	ft_strstr.c ft_strnstr.c ft_strcmp.c ft_strncmp.c \
	ft_atoi.c ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c \
	ft_isprint.c ft_islower.c ft_isupper.c \
	ft_strupcase.c ft_strlowcase.c ft_toupper.c ft_tolower.c \
	ft_strnew.c ft_strdel.c ft_strclr.c \
	ft_striter.c ft_striteri.c ft_strmap.c ft_strmapi.c \
	ft_strequ.c ft_strnequ.c ft_strsub.c ft_strjoin.c \
	ft_strtrim.c ft_strsplit.c ft_itoa.c \
	ft_cntword.c ft_strrlen.c ft_strndup.c ft_strdeltab.c

DISPDIR = src/display
FT_DISP = ft_putchar.c ft_putstr.c ft_putendl.c ft_putnbr.c \
	ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c

LSTDIR = src/list
FT_LST = ft_lstnew.c ft_lstdelone.c ft_lstdel.c ft_lstadd.c \
	ft_lstiter.c ft_lstmap.c

MATHDIR = src/math
FT_MATH = ft_cntdigit.c ft_pow.c ft_sqrt.c

OBJDIR = obj
VPATH = $(MEMDIR):$(STRDIR):$(DISPDIR):$(LSTDIR):$(MATHDIR)
SRC = $(FT_MEM) $(FT_STR) $(FT_DISP) $(FT_LST) $(FT_MATH)
OBJ = $(addprefix $(OBJDIR)/, $(SRC:.c=.o))

# Dude colors lmao
GOOD=\x1b[32;01m
AIGHT=\x1b[33;01m
WARN=\x1b[31;01m
NOCOLOR=\x1b[0m
ifeq ($(shell uname), Linux)
	ECHO = echo -e
else
	ECHO = echo
endif

.PHONY: all so clean fclean re

all: $(NAME)

$(NAME): $(OBJ)
	@$(AR) rc $(NAME) $(OBJ)
	@ranlib $(NAME)
	@$(ECHO) "$(GOOD)[LIBFT]Archived library updated.$(NOCOLOR)"

$(SONAME): CFLAGS += -fPIC
$(SONAME): $(OBJ)
	@$(CC) -shared -o $(SONAME) $(OBJ)
	@$(ECHO) "$(GOOD)[LIBFT]Shared object updated.$(NOCOLOR)"

so: $(SONAME)

$(OBJDIR):
	mkdir -p $(OBJDIR)

$(OBJDIR)/%.o: %.c $(INCFULL) | $(OBJDIR)
	@$(ECHO) "$(GOOD)[LIBFT]$(AIGHT)[$(dir $<)]$(NOCOLOR)$(notdir $(@:.o=))"
	@$(CC) $(CFLAGS) -c -o $@ $< $(INC)

# Cleanup
clean:
	@$(RM) -r $(OBJDIR)
	@$(ECHO) "$(GOOD)[LIBFT]$(WARN)[CLEAN]$(NOCOLOR)Object directory removed"

fclean: clean
	@$(RM) $(NAME) $(SONAME)
	@$(ECHO) "$(GOOD)[LIBFT]$(WARN)[CLEAN]$(NOCOLOR)Archive removed"

re: fclean all
