# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pweinsto <pweinsto@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/08/19 16:48:53 by pweinsto          #+#    #+#              #
#    Updated: 2021/08/21 11:17:19 by pweinsto         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME_CLIENT = client

NAME_SERVER = server

CLIENT_SRCS =	client.c

SERVER_SRCS =	server.c

LIBFT_PATH	= ./includes/libft

CC		=		gcc

CFLAGS	=	-Werror -Wextra -Wall

O = -o

RM		=		rm -f

all: 		target_libft $(NAME_CLIENT) $(NAME_SERVER)

target_libft:		
			make -C $(LIBFT_PATH)

$(NAME_CLIENT): target_libft
			$(CC) $(CFLAGS) $(O) $(NAME_CLIENT) $(CLIENT_SRCS) $(LIBFT_PATH)/libft.a

$(NAME_SERVER): target_libft
			$(CC) $(CFLAGS) $(O) $(NAME_SERVER) $(SERVER_SRCS) $(LIBFT_PATH)/libft.a

clean:
			make clean -C $(LIBFT_PATH)

fclean_libft:
			make fclean -C $(LIBFT_PATH)

fclean:		clean fclean_libft 
			$(RM) $(NAME_CLIENT) $(NAME_SERVER)

re:			fclean all