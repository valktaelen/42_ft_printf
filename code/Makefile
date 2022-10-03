# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aartiges <aartiges@student.42lyon.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/15 21:17:16 by aartiges          #+#    #+#              #
#    Updated: 2022/10/03 22:18:59 by aartiges         ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #

SRCS =	ft_ntoa_gen.c ft_printf.c ft_utils.c ft_alloc.c ft_convert.c

OBJS = ${SRCS:.c=.o}

HEADERS =	ft_printf.h

NAME = libftprintf.a
CC = gcc
CFLAGS = -Wall -Wextra -Werror
RM = rm -rf
LIBC = ar
LIBF = rcs
LIBFT_SRC = libft/code/
LIBFT_LIB = $(LIBFT_SRC)libft.a

%.o : %.c  $(HEADERS)
	${CC} ${CFLAGS} -c $< -o $@ 

all: 		${NAME}

$(LIBFT_LIB) : $(LIBFT_SRC)*.c $(LIBFT_SRC)*.h
	make -C $(LIBFT_SRC) bonus

$(NAME):	$(OBJS) $(LIBFT_LIB)
			cp $(LIBFT_LIB) $(NAME)
			$(LIBC) $(LIBF) $(NAME) $(OBJS)

clean:
			${RM} ${OBJS}
			make -C $(LIBFT_SRC) clean

miclean:
		${RM} ${OBJS}

fclean: miclean
			${RM} ${NAME}
			make -C $(LIBFT_SRC) fclean

re: fclean all
