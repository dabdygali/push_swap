# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dabdygal <dabdygal@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/15 15:43:23 by dabdygal          #+#    #+#              #
#    Updated: 2023/11/03 12:13:07 by dabdygal         ###   ########.fr        #
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

CFLAGS = -Wall -Wextra -Werror -I $(INCLUDE_DIR)

SRC_FILES = init_stacks.c \
			free_mem.c \
			push_swap_rules_0.c \
			push_swap_rules_1.c \
			sort_stack_print.c \
			printed_rules_0.c \
			printed_rules_1.c \
			printed_rules_2.c \
			sorted_push_b_0.c \
			sorted_push_b_1.c \
			sorted_push_b_2.c \
			set_ops_0.c \
			align_a.c

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
