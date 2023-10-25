# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dabdygal <dabdygal@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/15 15:43:23 by dabdygal          #+#    #+#              #
#    Updated: 2023/10/25 15:31:00 by dabdygal         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# *********************************INITIALIZE********************************* #

BIN_NAME = push_swap

SRC_DIR = src

OBJ_DIR = src

LIBFT_NAME = libft.a

LIBFT_DIR = libft

INCLUDE_DIR = include

CC = cc

CFLAGS = -Wall -Wextra -Werror -I $(INCLUDE_DIR) -fsanitize=address

SRC_FILES = parse_args.c

MAIN_DIR = .

MAIN_FILE = push_swap.c

OBJ_FILES = $(SRC_FILES:.c=.o)

# ************************************RULES*********************************** #

$(BIN_NAME): $(addprefix $(LIBFT_DIR)/,$(LIBFT_NAME)) $(addprefix $(MAIN_DIR)/,$(MAIN_FILE)) $(addprefix $(SRC_DIR)/,$(SRC_FILES))
	$(CC) $(CFLAGS) $(addprefix $(MAIN_DIR)/,$(MAIN_FILE)) $(addprefix $(SRC_DIR)/,$(SRC_FILES)) $(addprefix $(LIBFT_DIR)/,$(LIBFT_NAME)) -o $(BIN_NAME)

$(addprefix $(LIBFT_DIR)/,$(LIBFT_NAME)):
	make $(LIBFT_NAME) -C $(LIBFT_DIR)

all: $(BIN_NAME)

clean:
	make clean -C $(LIBFT_DIR)

fclean: clean
	rm -f $(BIN_NAME)
	make fclean -C $(LIBFT_DIR)

re: fclean all

.PHONY: all clean fclean re
