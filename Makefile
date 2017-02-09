# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: imoran <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/01/24 16:30:09 by imoran            #+#    #+#              #
#    Updated: 2017/01/24 16:30:10 by imoran           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
NAME = fillit

CFLAGS += -Wall -Wextra -Werror

SRCS = main read free result process_tetro print

CFILES = $(addprefix ./src/, $(addsuffix .c, $(SRCS)))

OBJS = *.o


all: $(NAME)

$(NAME):
	gcc $(CFLAGS) -c $(CFILES) -Ifillitlib.h
	gcc $(CFLAGS) $(OBJS) -L./libft -lft -o $(NAME)

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

re: fclean all
