# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: bandrade <bandrade@student.42.fr>            +#+                      #
#                                                    +#+                       #
#    Created: 2026/04/13 13:02:20 by pride-ol      #+#    #+#                  #
#    Updated: 2026/04/29 19:01:05 by pride-ol      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
CC = cc
CFLAGS = -Wall -Wextra -Werror -I. -Ilibft

# libft variables
LIBFT_DIR = ./libft
LIBFT = $(LIBFT_DIR)/libft.a

SRCS = main.c \
	sort_handler.c \
	sort_3_5.c \
	simple_sort.c \
	simple_utils.c \
	sorting_helpers.c \
	indexing.c \
	chunk_sort.c \
	chunk_utils.c \
	radix_sort.c \
	parsing.c \
	parsing_helpers.c \
	utils.c \	
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