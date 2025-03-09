# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mboutahi <mboutahi@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/03/04 20:09:36 by mboutahi          #+#    #+#              #
#    Updated: 2025/03/04 20:09:38 by mboutahi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC=cc
CFLAGS= -Wall -Wextra -Werror
SOURCE_SERVER= server.c utils.c
SOURCE_CLIENT= client.c utils.c

OBJ_SERVER=$(SOURCE_SERVER:.c=.o)
OBJ_CLIENT=$(SOURCE_CLIENT:.c=.o)

NAME_SERVER=server
NAME_CLIENT=client

all:$(NAME_SERVER) $(NAME_CLIENT)

$(NAME_SERVER):	$(OBJ_SERVER)
	$(CC) $(CFLAGS) $(OBJ_SERVER) -o $(NAME_SERVER)

$(NAME_CLIENT):	$(OBJ_CLIENT)
	$(CC) $(CFLAGS) $(OBJ_CLIENT) -o $(NAME_CLIENT)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ_SERVER) $(OBJ_CLIENT)
fclean: clean
	rm -f $(NAME_SERVER) $(NAME_CLIENT)
