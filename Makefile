# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mvan-vel <mvan-vel@student.s19.be>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/08/12 16:28:20 by mvan-vel          #+#    #+#              #
#    Updated: 2024/08/25 15:31:46 by mvan-vel         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#---------------------------------------------------------#
CC		=	cc

CFLAGS	=	-Wall -Wextra -Werror

GFLAGS	=	-g

# DFLAGS	=	-fsanitize=address -fsanitize=undefined

#---------------------------------------------------------#
SRC_DIR	=	src

SRC		=	$(shell find $(SRC_DIR) -type f -name "*.c")

OBJ_DIR	=	obj

OBJ		=	$(SRC:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

INC_DIR	=	Include

LIB_DIR	=	libft

LIB		=	$(LIB_DIR)/libft.a


.PHONY: all lib clean fclean libclean re

#---------------------------------------------------------#
NAME	=	push_swap

all:		$(NAME)

lib:		$(LIB)

$(NAME):	$(OBJ) $(LIB)
	$(CC) $(CFLAGS) $(GFLAGS) $(OBJ) -o $@ -L$(LIB_DIR) -lft

$(LIB):
	$(MAKE) -C $(LIB_DIR)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) $(GFLAGS) -I$(INC_DIR) -I$(LIB_DIR)/$(INC_DIR) -c $< -o $@

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)/$(OP_DIR)

#---------------------------------------------------------#
clean:
	rm -rf $(OBJ_DIR)

fclean:		clean
	rm -rf $(NAME) *dSYM

libclean:
	rm -rf $(LIB_DIR)/$(OBJ_DIR)
	rm -rf $(LIB)

re: fclean all
libre: libclean lib
#---------------------------------------------------------#