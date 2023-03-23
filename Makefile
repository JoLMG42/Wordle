# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cdefonte <cdefonte@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/29 12:16:09 by cdefonte          #+#    #+#              #
#    Updated: 2023/03/22 18:57:30 by jtaravel         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = wordle

SRC_DIR = src/
OBJ_DIR = obj/
INC_DIR = inc/
LIBFT_DIR = libft/
LIBFT = $(LIBFT_DIR)libft.a

SRC_LST = main.c token_lst.c

INCLUDES = -I$(LIBFT_DIR) -I$(INC_DIR)

SRC = $(addprefix $(SRC_DIR), $(SRC_LST))
OBJ = $(patsubst $(SRC_DIR)%.c, $(OBJ_DIR)%.o, $(SRC))
HEADERS = $(INC_DIR)wordle.h

CC = cc
CFLAGS = -Wall -Wextra -Werror
#CFLAGS = -Wall -Wextra -Werror 
RM = rm -f

all: $(NAME)

$(NAME): $(HEADERS) $(OBJ) $(LIBFT)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ) -L$(LIBFT_DIR) -lft -lreadline

$(OBJ_DIR)%.o: $(SRC_DIR)%.c $(HEADERS)
	mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -o $@ -c $< $(INCLUDES)

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

clean:
	$(MAKE) $@ -C $(LIBFT_DIR)
	$(RM) $(OBJ)

fclean:
	$(MAKE) $@ -C $(LIBFT_DIR)
	$(RM) $(OBJ) $(NAME)

re: fclean all

libft :
	$(MAKE) -C $(LIBFT_DIR)

.PHONY: all clean fclean re libft
