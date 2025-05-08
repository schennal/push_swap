# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: schennal <schennal@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/18 18:11:24 by schennal          #+#    #+#              #
#    Updated: 2023/05/31 23:29:53 by schennal         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

SRCS = \
	push_swap.c \
	check_ip.c \
	check_sort.c \
	check.c \
	chunk_sort.c \
	create_array.c \
	error.c \
	operations.c \
	sort_four_five.c \
	sort.c \
	utils_extra.c \
	utils_other.c \
	utils_sort.c \
	valid_array.c \
	
OBJS := $(SRCS:.c=.o)

CC	= gcc
CFLAGS = -Wall -Wextra -Werror -g3
RM = rm -rf

all: $(NAME)

$(NAME): $(SRCS)
			$(CC) $(CFLAGS) $(SRCS) -o $(NAME)

clean : 
		$(RM) $(OBJS)

fclean : clean
		$(RM) $(NAME)


re : fclean all

PHONY : all bonus fclean re