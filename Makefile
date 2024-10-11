# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cbourre <cbourre@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/16 15:29:59 by cbourre           #+#    #+#              #
#    Updated: 2023/03/06 13:22:23 by cbourre          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#### FILES #####################################################################

NAME = push_swap

SRC = args_checker.c \
	check_if.c \
	error_message.c \
	find_num.c \
	ft_free.c \
	ft_sorting.c \
	little_sorting.c \
	normalise.c \
	lst.c \
	push_swap.c

OP = ft_swap.c \
	ft_push.c \
	ft_rotate.c \
	ft_reverse_rotate.c

SRCS = $(addprefix srcs/, $(SRC)) \
		$(addprefix srcs/operations/, $(OP))

OBJS = $(SRCS:.c=.o)

########## LIBFT

LIB_DIR =	libft

LIB_NAME =	libft/libft.a


#### COMPIL ####################################################################

CC =		clang

CFLAGS =	-Wall -Wextra -Werror -I. -g

RM =		rm -rf


#### RULES #####################################################################

all: $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(LIB_NAME):
	make -sC $(LIB_DIR)

$(NAME): $(OBJS) $(LIB_NAME)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LIB_NAME)


#### BIN #######################################################################

clean:
	$(RM) $(OBJS)
	make -sC $(LIB_DIR) clean

fclean: clean
	$(RM) $(NAME)
	make -sC $(LIB_DIR) fclean

re: fclean all

.PHONY: all clean fclean re
