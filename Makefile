# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gblas-he <gblas-he@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/02/02 16:03:25 by gblas-he          #+#    #+#              #
#    Updated: 2026/02/06 17:06:07 by gblas-he         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
CC = cc
CFLAGS = -Wall -Wextra -Werror
	

SRCS = ft_printf.c
OBJS = $(SRCS:.c=.o)
INCLUDE = libftprintf.h
	
AR = ar rcs
RM = rm -f

.PHONY: all clean fclean re
bonus: all

all: $(NAME)
	

$(NAME): $(OBJS)
	$(AR) $@ $^

%.o: %.c $(INCLUDE)
	$(CC) $(CFLAGS) -c -o $@ $<
	

clean:
	$(RM) $(OBJS)
	

fclean: clean
	$(RM) $(NAME)
	

re: fclean all
	

