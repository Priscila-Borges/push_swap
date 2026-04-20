# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: bandrade <bandrade@student.42.fr>            +#+                      #
#                                                    +#+                       #
#    Created: 2026/04/13 13:02:20 by pride-ol      #+#    #+#                  #
#    Updated: 2026/04/20 17:11:25 by pride-ol      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
CC = cc
CFLAGS = -Wall -Wextra -Werror -Ilibft

# libft variables
LIBFT_DIR = ./libft
LIBFT = $(LIBFT_DIR)/libft.a

SRCS = main.c \
	 sort_handler.c \
	 parsing.c \
	 helper_functions.c \
	 push.c \
	 swap.c \
	 rotate.c \
	 rev_rotate.c 
OBJS = $(SRCS:.c=.o)

all: $(NAME)
$(NAME): $(LIBFT) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME)
$(LIBFT):
	make -C $(LIBFT_DIR)
clean:
	rm -f $(OBJS)
	make -C $(LIBFT_DIR) clean
fclean: clean
	rm -f $(NAME)
	make -C $(LIBFT_DIR) fclean
re: fclean all
.PHONY: all re clean fclean