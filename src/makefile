# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sezequie <sezequie@student.42lisboa.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/03 09:57:46 by sezequie          #+#    #+#              #
#    Updated: 2024/06/03 11:29:49 by sezequie         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	pipex

FILES		=	main.c \
				pipe_handling.c \
				utils.c

OBJS		=	$(FILES:.c=.o)

RM			=	rm -f

CC			=	cc

CFLAGS		=	-Wall -Wextra -Werror -g #-fsanitize=address

PRINT_PATH	=	../Libft/Printf --no-print-directory
PRINT_NAME	=	../Libft/Printf/libftprintf.a

LIBFT_PATH	=	../Libft --no-print-directory
LIBFT_NAME	=	../Libft/libft.a

all: $(PRINT_NAME) $(LIBFT_NAME) $(NAME)

$(PRINT_NAME):
	@make -C $(PRINT_PATH)

$(LIBFT_NAME):
	@make -C $(LIBFT_PATH)

$(NAME):	$(OBJS)
			$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LIBFT_NAME) $(PRINT_NAME)

clean:
		@make fclean -C $(PRINT_PATH)
		@make fclean -C $(LIBFT_PATH)
		$(RM) $(OBJS)

fclean:		clean
		$(RM) $(NAME)

re:		fclean all