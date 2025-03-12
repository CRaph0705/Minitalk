# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rcochran <rcochran@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/03/06 14:34:41 by rcochran          #+#    #+#              #
#    Updated: 2025/03/12 18:44:39 by rcochran         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY : all clean fclean re

CC			= 	cc
CFLAGS		= 	-Wall -Werror -Wextra
AR			=	ar -rcs
NAME		= 	client server
BNAME		=	bclient bserver

LIBFT_PATH	=	./libft
LIBFT		=	$(LIBFT_PATH)/libft.a

INCLUDES	= -I$(LIBFT_PATH)/includes
BINCLUDES	=	-I ./bonus

SRC_DIR		= 	src/
SRC_BDIR	= 	src_bonus/


all : $(NAME)

clean :
	rm -rf $(OBJ_DIR)
	rm -rf $(BOBJ_DIR)
	make clean -C $(LIBFT_PATH)

fclean : clean
	rm -f $(NAME)
	rm -f $(BNAME)
	rm -f $(LIBFT)

re : fclean all

client : $(LIBFT)
	$(CC) $(CFLAGS) $(INCLUDES) -o $@ $(SRC_DIR)client.c -L$(LIBFT_PATH) -lft

server : $(LIBFT)
	$(CC) $(CFLAGS) $(INCLUDES) -o $@ $(SRC_DIR)server.c -L$(LIBFT_PATH) -lft

bclient : $(LIBFT)
	$(CC) $(CFLAGS) $(INCLUDES) -o client $(SRC_BDIR)client_bonus.c -L$(LIBFT_PATH) -lft

bserver : $(LIBFT)
	$(CC) $(CFLAGS) $(INCLUDES) -o server $(SRC_BDIR)server_bonus.c -L$(LIBFT_PATH) -lft

$(LIBFT):
	make -C $(LIBFT_PATH)

bonus: $(BNAME)

rebonus: fclean bonus

