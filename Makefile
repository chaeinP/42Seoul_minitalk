# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: chaepark <chaepark@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/21 23:25:53 by chaepark          #+#    #+#              #
#    Updated: 2022/04/27 00:59:11 by chaepark         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minitalk
SERVER = server
CLIENT = client
CC = gcc
CFLAGS = -Wall -Wextra -Werror

all: $(SERVER) $(CLIENT)

$(NAME): all

$(SERVER):
	$(CC) $(CFLAGS) server.c utils.c -o $(SERVER)

$(CLIENT):
	$(CC) $(CFLAGS) client.c utils.c -o $(CLIENT)

clean:
	rm $(CLIENT) $(SERVER)

fclean: clean

re: fclean all
