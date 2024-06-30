# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gtsuchid <gtsuchid@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/30 12:51:26 by gtsuchid          #+#    #+#              #
#    Updated: 2024/06/30 13:39:21 by gtsuchid         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME    =   libftprintf.a
CC      =   cc
CFLAGS  =   -Wall -Wextra -Werror
AR      =   ar rcs
RM      =   rm -f
INCS    =   ft_printf.h
SRCS    =   ft_printf.c put_c.c put_s.c put_p.c put_di.c put_u.c \
            put_x.c put_x2.c put_per.c ft_putchar_fd_2.c ft_putstr_fd_2.c
OBJS    =   $(SRCS:.c=.o)

$(NAME): $(OBJS)
	$(AR) $(NAME) $(OBJS)

all: $(NAME)

bonus: all

%.o: %.c
	$(CC) $(CFLAGS) -I $(INCS) -c $< -o $@

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all bonus clean fclean re
