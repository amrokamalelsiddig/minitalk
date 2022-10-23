# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aelsiddi <aelsiddi@student.42abudhabi.a    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/24 16:26:31 by aelsiddi          #+#    #+#              #
#    Updated: 2022/10/20 19:19:43 by aelsiddi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= server
NAME_2	= client
CC		= gcc
CFLAGS	=	-Wall -Wextra -Werror
SRCS	= client.c server.c
OBJ		=	$(SRC:.c=.o)

all: ${NAME} ${NAME_2}	${OBJ}

$(NAME):
		$(CC) $(CFLAGS) server.c -o$@
$(NAME_2):
		$(CC) $(CFLAGS) client.c -o$@
clean:
		${RM} ${OBJ}

fclean: clean
		${RM} ${NAME} ${NAME_2} ${NAME_3}

re:	fclean all

norm:
	norminette $(SRC) $(name:.h)

.PHONY: all clean fclean re