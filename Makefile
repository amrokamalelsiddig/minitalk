# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aelsiddi <aelsiddi@student.42abudhabi.a    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/24 16:26:31 by aelsiddi          #+#    #+#              #
#    Updated: 2022/09/24 18:12:33 by aelsiddi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

LIBFT_PATH	=	"../libft"

LIBFT		= $(LIBFT_PATH)/libft.a

SRCS		=	client.c\
				server.c
				
NAME 		=	minitalk
CC			=	cc
FLAGS		=	-Wall -Wextra -Werror
RM			=	rm -rf
OBJES 		= ${SRCS:.c=.o}


%.o : %.c
	   ${CC} ${CFLAGS} -c $< -o $@

${NAME} : ${OBG}
		${AR}
		
all: ${NAME}

bonus: ${OBG_B}
	${AR} ${NAME}

clean:
		${RM} ${OBG}

fclean: clean
		${RM} ${NAME}

re:	fclean all

.PHONY: all clean fclean re bonu