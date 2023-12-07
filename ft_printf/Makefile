# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rpliego <rpliego@student.42barcelo>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/20 13:01:00 by rpliego           #+#    #+#              #
#    Updated: 2023/05/20 13:01:03 by rpliego          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

LIB = ar rcs
RM = rm -f

CC = cc
CCFLAGS = -Wall -Wextra -Werror

NAME = libftprintf.a
SRC = 	ft_printf.c \
		ft_printc.c \
		ft_printstr.c \
		ft_printptr.c \
		ft_printnbr.c \
		ft_printunsigned.c \
		ft_printhexlow.c \
		ft_printhexup.c
OBJ = $(SRC:.c=.o)
INCLUDE = ft_printf.h

all: $(NAME)

$(NAME): $(OBJ) $(INCLUDE)
	$(LIB) $(NAME) $(OBJ)

%.o: %.c
	$(CC) $(CCFLAGS) -c -o $@ $< 

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re