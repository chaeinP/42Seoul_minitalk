# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: chaepark <chaepark@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/21 23:25:53 by chaepark          #+#    #+#              #
#    Updated: 2022/04/29 18:30:02 by chaepark         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minitalk
SERVER = server
CLIENT = client
SRC = server.c client.c utils.c
OBJ = ${SRC:.c=.o}
CC = gcc
CFLAGS = -Wall -Wextra -Werror

$(NAME): $(SERVER) $(CLIENT)

$(SERVER): ${OBJ}
	$(CC) $(CFLAGS) server.o utils.o -o $(SERVER)

$(CLIENT): ${OBJ}
	$(CC) $(CFLAGS) utils.o client.o -o $(CLIENT)

.c.o:
	$(CC) $(CFLAGS) -c $< -o ${<:.c=.o}

all: $(NAME)

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf server client

re: fclean all

.PHONY:	all clean fclean re
