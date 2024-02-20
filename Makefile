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

# Nombre del ejecutable
# Executable's name
NAME = push_swap

# Directorios
SRC_DIR = source
INC_DIR = includes
COMMANDS_DIR = $(SRC_DIR)/commands
DPRO_DIR = $(SRC_DIR)/dpro

# Compilador
# Compiler
CC = gcc

# Opciones de compilación
# Compilation flags
CFLAGS = -Wall -Wextra -Werror -MMD # -g 

# Archivos fuente
# Source files
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


# Objetos generados por la compilación
# Compilation objects
OBJS = $(SRCS:.c=.o)

DEPS = $(SRCS:.c=.d)

all: $(NAME)

# Regla principal para construir el ejecutable
# Lead target
- include: $(DEPS)
$(NAME): $(OBJS) 
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

# Regla para compilar cada archivo fuente individualmente
# target to compile all, one by one
%.o: %.c %.h Makefile
	$(CC) $(CFLAGS) -I./$(SRC_DIR) -I./$(INC_DIR) -c $< -o $@

# Regla para limpiar archivos generados durante la compilación
# target to clean compiling flags
clean:
	rm -f $(OBJS) $(DEPS)

# FULL CLEAN 
fclean: clean
	rm -f $(NAME)

re: fclean all

# Phony target para evitar conflictos con archivos del mismo nombre
# target to avoid conflicts on files and target 
.PHONY: all clean fclean re

