# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jbarbate <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/29 10:45:24 by jbarbate          #+#    #+#              #
#    Updated: 2023/01/10 09:05:17 by jbarbate         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

GCC = gcc
SRCS = src/main.c src/pipex.c src/tools.c
SRCS_BONUS = bonus/main.c bonus/pipex.c bonus/tools.c bonus/here_doc.c
LIBFT = libft/libft.a
OBJS = ${SRCS:.c=.o}
OBJS_BONUS = ${SRCS_BONUS:.c=.o}
NAME = pipex
CFLAGS = -Wall -Wextra -Werror

.c.o:
	${GCC} ${CFLAGS} -c $< -o ${<:.c=.o}

${NAME}: ${OBJS}
	@make -C libft all
	${GCC} ${CFLAGS} -o ${NAME} ${LIBFT} ${OBJS}

all: ${OBJS} ${NAME}

bonus: ${OBJS_BONUS}
	@make -C libft all
	${GCC} ${CFLAGS} -o ${NAME} ${LIBFT} ${OBJS_BONUS}

clean: libclean bonusclean
	@rm -f ${OBJS}
	@echo Everything is clean

libclean:
	@make -C libft fclean

bonusclean:
	@rm -f ${OBJS_BONUS}

fclean: clean
	@rm -f ${NAME}

re: fclean all
