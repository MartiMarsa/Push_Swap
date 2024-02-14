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
NAME = push_swap

# Directorios
SRC_DIR = source
INC_DIR = includes
COMMANDS_DIR = $(SRC_DIR)/commands
DPRO_DIR = $(SRC_DIR)/dpro
OBJ_DIR = obj

# Compilador
CC = gcc

# Opciones de compilación
CFLAGS = -Wall -Wextra -Werror -g -I$(SRC_DIR) -I./$(INC_DIR) 

# Archivos fuente
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
	$(DPRO_DIR)/splitf.c \
	$(DPRO_DIR)/update_nodes_a_to_b.c \
	$(DPRO_DIR)/update_nodes_b_to_a.c \


# Objetos generados por la compilación
OBJS = $(SRCS:.c=.o)

all: $(NAME)

# Regla principal para construir el ejecutable
$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

# Regla para compilar cada archivo fuente individualmente
%.o: %.c Makefile
	$(CC) $(CFLAGS) -c $< -o $@

# Regla para limpiar archivos generados durante la compilación
clean:
	rm -f $(OBJS) $(DEPS)

# FULL CLEAN 
fclean: clean
	rm -f $(NAME)

re: fclean all

# Phony target para evitar conflictos con archivos del mismo nombre
.PHONY: all clean fclean re

