# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jbarbate <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/08 07:03:24 by jbarbate          #+#    #+#              #
#    Updated: 2023/01/06 13:30:59 by jbarbate         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

GCC = gcc
SRCS = ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c \
       ft_strlen.c ft_toupper.c ft_tolower.c ft_strchr.c ft_strrchr.c \
       ft_strncmp.c ft_strlcpy.c ft_strlcat.c ft_memset.c ft_memcpy.c \
       ft_bzero.c ft_memmove.c ft_memchr.c ft_memcmp.c ft_strnstr.c \
       ft_atoi.c ft_calloc.c ft_strdup.c ft_putchar_fd.c ft_putstr_fd.c \
       ft_putendl_fd.c ft_putnbr_fd.c ft_substr.c ft_strjoin.c ft_strtrim.c \
       ft_itoa.c ft_strmapi.c ft_striteri.c ft_split.c ft_lstadd_back.c \
       ft_lstadd_front.c ft_lstlast.c ft_lstnew.c ft_lstsize.c ft_lstdelone.c \
       ft_lstclear.c ft_lstiter.c ft_lstmap.c ft_strcmp.c get_next_line.c \
	   get_next_line_utils.c
HEADER = -I libft.h
OBJS = ${SRCS:.c=.o}
NAME = libft.a
CFLAGS = -Wall -Wextra -Werror

.c.o:
	@${GCC} ${CFLAGS} ${HEADER} -c $< -o ${<:.c=.o}

${NAME}: ${OBJS}
	@ar rcs ${NAME} ${OBJS}

all: ${OBJS} ${NAME}

clean:
	@rm -f ${OBJS}

fclean: clean
	@rm -f ${NAME}

re: fclean all
