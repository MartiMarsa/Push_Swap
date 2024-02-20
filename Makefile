# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mmarsa-s <mmarsa-s@student.42barcel>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/09 15:07:49 by mmarsa-s          #+#    #+#              #
#    Updated: 2024/01/09 15:07:51 by mmarsa-s         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

SRC_DIR = source
INC_DIR = includes
COMMANDS_DIR = $(SRC_DIR)/commands
DPRO_DIR = $(SRC_DIR)/dpro

CC = gcc

CFLAGS = -Wall -Wextra -Werror -MMD # -g 

SRCS = \
	$(COMMANDS_DIR)/push.c \
	$(COMMANDS_DIR)/reverse_rotate.c \
	$(COMMANDS_DIR)/rotate.c \
	$(COMMANDS_DIR)/sort_stacks.c \
	$(COMMANDS_DIR)/sort_three.c \
	$(COMMANDS_DIR)/swap.c \
	$(DPRO_DIR)/handle_errors.c \
	$(DPRO_DIR)/init_stacks.c \
	$(DPRO_DIR)/main.c \
	$(DPRO_DIR)/push_swap_utils.c \
	$(DPRO_DIR)/update_nodes_a_to_b.c \
	$(DPRO_DIR)/update_nodes_b_to_a.c \


OBJS = $(SRCS:.c=.o)

DEPS = $(SRCS:.c=.d)

INC = $(INC_DIR)/push_swap.h

all: $(NAME)

- include: $(DEPS)
$(NAME): $(OBJS) 
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

%.o: %.c $(DEPS) Makefile
	$(CC) $(CFLAGS) -I./$(SRC_DIR) -I./$(INC_DIR) -c $< -o $@

clean:
	rm -f $(OBJS) $(DEPS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re

