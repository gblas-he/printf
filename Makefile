# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gblas-he <gblas-he@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/02/02 16:03:25 by gblas-he          #+#    #+#              #
#    Updated: 2026/03/21 21:29:36 by gblas-he         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
EXEC = test_printf

CC = cc
CFLAGS = -Wall -Wextra -Werror -g
	

SRCS = ft_printf.c ft_printf_chars.c ft_printf_nums.c 
OBJS = $(SRCS:.c=.o)
INCLUDE = ft_printf.h 
	
AR = ar rcs
RM = rm -f

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(OBJS)
	$(AR) $@ $^

%.o: %.c $(INCLUDE)
	$(CC) $(CFLAGS) -c -o $@ $<

test: $(NAME)
	$(CC) $(CFLAGS) main.c $(NAME) -o $(EXEC)
	$(MAKE) clean
	./$(EXEC)
	
	
clean:
	$(RM) $(OBJS)
	

fclean: clean
	$(RM) $(NAME) $(EXEC)
	

re: fclean all
	

