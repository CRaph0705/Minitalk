# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rcochran <rcochran@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/03/06 14:34:41 by rcochran          #+#    #+#              #
#    Updated: 2025/03/06 20:23:06 by rcochran         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY : all clean fclean re

CC			= 	cc
CFLAGS		= 	-Wall -Werror -Wextra
AR			=	ar -rcs
NAME		= 	######
BNAME		=	######

LIBFT_PATH	=	./libft
LIBFT		=	$(LIBFT_PATH)/libft.a

INCLUDES	= -I$(LIBFT_PATH)/includes -I ./includes
BINCLUDES	=	-I ./bonus

FILES		=	######
BFILES		=	######

MAIN		=	main.c
BMAIN		=	main_bonus.c

SRC_FILES	=	$(addsuffix .c, $(FILES))
SRC_BFILES	= 	$(addsuffix .c, $(BFILES))

OBJ_DIR		= 	obj/
BOBJ_DIR	= 	bobj/

SRC_DIR		= 	src/
SRC_BDIR	= 	bonus/

SRC			=	$(addprefix $(SRC_DIR), $(SRC_FILES))
BSRC		= 	$(addprefix $(SRC_BDIR), $(SRC_BFILES))

OBJ			=	$(patsubst $(SRC_DIR)%.c, $(OBJ_DIR)%.o, $(SRC))
BOBJ		=	$(patsubst $(SRC_BDIR)%.c, $(BOBJ_DIR)%.o, $(BSRC))

OBJ_MAIN	=	$(patsubst $(SRC_DIR)%.c, $(OBJ_DIR)%.o, $(SRC_DIR)$(MAIN))
OBJ_BMAIN	=	$(patsubst $(SRC_BDIR)%.c, $(BOBJ_DIR)%.o, $(SRC_BDIR)$(BMAIN))

all : server client

# all : $(NAME)

clean :
	rm -rf $(OBJ_DIR)
	rm -rf $(BOBJ_DIR)
	make clean -C $(LIBFT_PATH)

fclean : clean
	rm -f $(NAME)
	rm -f $(LIBFT)
# rm -f checker

re : fclean all

$(NAME) : $(LIBFT) $(OBJ_DIR) $(OBJ) $(OBJ_MAIN)
	$(CC) $(CFLAGS) $(OBJ) $(OBJ_MAIN) -L$(LIBFT_PATH) -lft -o $(NAME)

$(LIBFT):
	make -C $(LIBFT_PATH)

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(BOBJ_DIR)%.o: $(SRC_BDIR)%.c
	$(CC) $(CFLAGS) $(INCLUDES) $(BINCLUDES) -c $< -o $@

$(OBJ_DIR) : 
	mkdir -p $(OBJ_DIR)

$(BOBJ_DIR) : 
	mkdir -p $(BOBJ_DIR)

debug : $(LIBFT) $(OBJ_DIR) $(OBJ)
	$(CC) -g $(CFLAGS) $(OBJ) -L$(LIBFT_PATH) -lft -o $(NAME)

# checker: $(OBJ) $(BOBJ_DIR) $(BOBJ) $(OBJ_BMAIN)
# 	$(CC) $(CFLAGS) $(OBJ) $(BOBJ) $(OBJ_BMAIN) -L$(LIBFT_PATH) -lft -o checker

# bonus: $(NAME) checker

# rebonus: fclean bonus

