# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lud-adam <lud-adam@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/20 10:37:40 by lud-adam          #+#    #+#              #
#    Updated: 2024/12/20 11:03:49 by lud-adam         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := libftprintf.a

H_FILES := ft_print.h

CC := cc

CFLAGS := -Wall -Werror -Wextra 

SRC = ft_printf.c ft_printf_utils.c \

LIBFT_DIR = ./libft

LIBFT = $(LIBFT_DIR)/libft.a

OBJ := $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ) 
	NAME := libftprintf.a

H_FILES := ft_print.h

CC := cc

CFLAGS := -Wall -Werror -Wextra 

SRC = ft_printf.c ft_printf_utils.c \

LIBFT_DIR = ./libft

LIBFT = $(LIBFT_DIR)/libft.a

OBJ := $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ) $(LIBFT) 
	cp $(LIBFT) $(NAME)
	ar -rcs $(NAME) $(OBJ)

%.o: %.c $(H_FILES) Makefile
	$(CC) $(CFLAGS) -c $< -o $@

$(LIBFT) :
	$(MAKE) -C $(LIBFT_DIR) 

clean:
	rm -rf *.o 
	$(MAKE) clean -C $(LIBFT_DIR)

fclean: clean
	rm -f $(NAME)
	$(MAKE) clean -C $(LIBFT_DIR)

re: fclean all

.PHONY: all clean fclean re
