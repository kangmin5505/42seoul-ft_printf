# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kangkim <kangkim@student.42seoul.k>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/03 17:04:19 by kangkim           #+#    #+#              #
#    Updated: 2021/12/03 20:25:23 by kangkim          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

CC = cc
CFLAGS = -Wall -Wextra -Werror
AR = ar rcs
RM = rm
RMFLAGS = -f

SRCS = ft_printf.c 				\
	fmt_info.c					\
	parse_specifier_detail.c	\
	print_character.c			\
	print_pointer.c				\
	print_decimal.c				\
	print_hexa.c				\
	print_percent.c				\
	
OBJS = $(SRCS:.c=.o)

# libft
LIBFT_DIR = libft
LIBFT_A = libft.a

all: $(NAME)

$(NAME): $(OBJS)
	make all -C $(LIBFT_DIR)
	cp $(LIBFT_DIR)/$(LIBFT_A) ./$(NAME)
	$(AR) $(NAME) $(OBJS)

.c.o:
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS)
	make clean -C $(LIBFT_DIR)

fclean : clean
	$(RM) $(RMFLAGS) $(NAME)
	make fclean -C $(LIBFT_DIR)

re : fclean all

.PHONY: all clean fclean re
