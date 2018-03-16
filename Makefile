# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: domelche <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/10/25 15:13:01 by domelche          #+#    #+#              #
#    Updated: 2017/11/14 13:13:31 by domelche         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit

LIB_NAME = libft.a

LIB_PATH = Libft/$(LIB_NAME)

SRCS = $(wildcard *.c)

OBJ = $(SRCS:.c=.o)

HEAD = libft.h fillit.h

CFLAGS = -Wall -Wextra -Werror

CC = gcc

.PHONY: all clean fclean re

.NOTPARALLEL: all clean fclean re

all: $(NAME)

$(NAME): $(OBJ)
	@cd Libft; $(MAKE); cd ..
	@$(CC) $(CFLAGS) $(SRCS) -o $(NAME) -L. $(LIB_PATH)

clean:
	@/bin/rm -f *.o
	@cd Libft; $(MAKE) clean; cd ..

fclean: clean
	@/bin/rm -f $(NAME)
	@cd Libft; $(MAKE) fclean; cd ..

re: fclean all
