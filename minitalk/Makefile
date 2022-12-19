# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aizsak <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/10 12:41:39 by aizsak            #+#    #+#              #
#    Updated: 2022/12/19 14:05:00 by aizsak           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CLIENT = client

SERVER = server

SRC_CLIENT =	src/client.c

SRC_SERVER =	src/server.c

CC = gcc

OBJ_SERVER = $(SRC_SERVER:.c=.o)

OBJ_CLIENT = $(SRC_CLIENT:.c=.o)

LIB_PATH = libft/

LIB = -Llibft -lft

INCLUDES = ./includes

CFLAGS =	-Werror -Wextra -Wall -I$(INCLUDES)

all :	$(CLIENT) $(SERVER)

$(SERVER) :     $(OBJ_SERVER)
			$(MAKE) -C $(LIB_PATH)
			$(CC) $(CFLAGS) $(OBJ_SERVER) $(LIB) -o $(SERVER)

$(CLIENT) :	$(OBJ_CLIENT)
			$(MAKE) -C $(LIB_PATH)
			$(CC) $(CFLAGS) $(OBJ_CLIENT) $(LIB) -o $(CLIENT)

clean :
	$(MAKE) clean -C $(LIB_PATH)
	rm -f $(OBJ_CLIENT) $(OBJ_SERVER)

fclean : clean
	$(MAKE) fclean -C $(LIB_PATH)
	rm -f $(CLIENT) $(SERVER)

re : fclean $(CLIENT) $(SERVER)

PHONY: all clean fclean re
