# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    MAKEFILE                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gtsuchid <gtsuchid@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/29 16:01:13 by gtsuchid          #+#    #+#              #
#    Updated: 2024/06/29 16:01:49 by gtsuchid         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	libft.a
CC			=	cc
CFLAGS		=	-Wall -Wextra -Werror
AR			=	ar rc
RM			=	rm -rf
PRINTF_DIR	=	ft_printf/
SRCS_DIR	=	srcs/
OBJS_DIR	=	objs/
INC_DIR		=	inc/
M_SRCS		=	srcs/mandantory/ft_atoi.c srcs/mandantory/ft_bzero.c srcs/mandantory/ft_calloc.c \
				srcs/mandantory/ft_isalnum.c srcs/mandantory/ft_isalpha.c srcs/mandantory/ft_isascii.c \
				srcs/mandantory/ft_isdigit.c srcs/mandantory/ft_isprint.c srcs/mandantory/ft_itoa.c \
				srcs/mandantory/ft_memchr.c srcs/mandantory/ft_memcmp.c srcs/mandantory/ft_memcpy.c \
				srcs/mandantory/ft_memmove.c srcs/mandantory/ft_memset.c srcs/mandantory/ft_putchar_fd.c \
				srcs/mandantory/ft_putendl_fd.c srcs/mandantory/ft_putnbr_fd.c srcs/mandantory/ft_putstr_fd.c \
				srcs/mandantory/ft_split.c srcs/mandantory/ft_strchr.c srcs/mandantory/ft_strdup.c \
				srcs/mandantory/ft_striteri.c srcs/mandantory/ft_strjoin.c srcs/mandantory/ft_strlcat.c \
				srcs/mandantory/ft_strlcpy.c srcs/mandantory/ft_strlen.c srcs/mandantory/ft_strmapi.c \
				srcs/mandantory/ft_strncmp.c srcs/mandantory/ft_strnstr.c srcs/mandantory/ft_strrchr.c \
				srcs/mandantory/ft_strtrim.c srcs/mandantory/ft_substr.c srcs/mandantory/ft_tolower.c \
				srcs/mandantory/ft_toupper.c srcs/mandantory/get_next_line.c
B_SRCS		=	srcs/ft_lstadd_back.c srcs/ft_lstadd_front.c srcs/ft_lstclear.c \
				srcs/ft_lstdelone.c srcs/ft_lstiter.c srcs/ft_lstlast.c \
				srcs/ft_lstmap.c srcs/ft_lstnew.c srcs/ft_lstsize.c
OBJS		=	$(patsubst $(SRCS_DIR)%.c, $(OBJS_DIR)%.o, $(M_SRCS))

ifdef			WITH_BONUS
				OBJS	+= $(patsubst $(SRCS_DIR)%.c, $(OBJS_DIR)%.o, $(B_SRCS))
endif



all:			$(NAME)

$(NAME):		$(OBJS)
	@ make -C $(PRINTF_DIR)
	@ cp $(PRINTF_DIR)libftprintf.a $@
	@ $(AR) $@ $^

$(OBJS_DIR)%.o : $(SRCS_DIR)%.c
	@ mkdir -p $(@D)
	@ $(CC) $(CFLAGS) -I $(INC_DIR) -c $< -o $@

bonus:
	@ make WITH_BONUS=1

clean:
	@ make clean -C $(PRINTF_DIR)
	@ $(RM) $(OBJS_DIR)

fclean:			clean
	@ make fclean -C $(PRINTF_DIR)
	@ $(RM) $(NAME)

re:				fclean all

.PHONY:			all bonus clean fclean re