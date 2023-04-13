# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aoubhoum <aoubhoum@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/04 17:01:17 by aoubhoum          #+#    #+#              #
#    Updated: 2023/03/07 20:39:32 by aoubhoum         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
FLAGS = -Wall -Werror -Wextra

all : client server

client : client.c minitalk.h ft_atoi.c
	$(CC) $(FLAGS) client.c ft_atoi.c -o client
	
server : server.c minitalk.h ft_putchar_fd.c ft_putnbr_fd.c
	$(CC) $(FLAGS) server.c  ft_putnbr_fd.c ft_putchar_fd.c -o server
	
clean :
	rm -rf client server

fclean : clean

re : fclean all
