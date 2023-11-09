# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: anchikri <anchikri@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/18 14:26:25 by anchikri          #+#    #+#              #
#    Updated: 2023/10/27 17:50:33 by anchikri         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC_CHECK =		ft_isalnum.c \
				ft_isalpha.c \
				ft_isascii.c \
				ft_isdigit.c \
				ft_isprint.c

SRC_STRING =	ft_strchr.c \
				ft_strdup.c \
				ft_strlcat.c \
				ft_strlcpy.c \
				ft_strlen.c \
				ft_strncmp.c \
				ft_strnstr.c \
				ft_strrchr.c \
				ft_strjoin.c \
				ft_strmapi.c \
				ft_strtrim.c \
				ft_substr.c \
				ft_split.c \
				ft_striteri.c

SRC_CONVERT =	ft_atoi.c \
				ft_itoa.c \
				ft_toupper.c \
				ft_tolower.c

SRC_MEMORY =	ft_bzero.c \
				ft_calloc.c \
				ft_memchr.c \
				ft_memcmp.c \
				ft_memcpy.c \
				ft_memmove.c \
				ft_memset.c 
				 

SRC_FD =		ft_putchar_fd.c \
				ft_putendl_fd.c \
				ft_putnbr_fd.c \
				ft_putstr_fd.c 

BONUS =			ft_lstnew_bonus.c \
				ft_lstadd_front_bonus.c \
				ft_lstsize_bonus.c \
				ft_lstlast_bonus.c \
				ft_lstadd_back_bonus.c \
				ft_lstdelone_bonus.c \
				ft_lstclear_bonus.c \
				ft_lstiter_bonus.c \
				ft_lstmap_bonus.c

SRCS =			${SRC_CHECK} \
				${SRC_STRING} \
				${SRC_CONVERT} \
				${SRC_MEMORY} \
				${SRC_FD} \


OBJS =			${SRCS:.c=.o}

BONUS_OBJS =	${BONUS:.c=.o}

CC = cc
CFLAGS = -Wall -Werror -Wextra
RM = rm -f
AR = ar rcs
NAME = libft.a

all:	$(NAME)

$(NAME):	${OBJS}
	$(AR) $(NAME) $(OBJS) 

clean:
	${RM} ${OBJS} ${BONUS_OBJS}

fclean:	clean
	${RM} ${NAME}

re:		fclean all

bonus:	${OBJS} ${BONUS_OBJS} 
	${AR} ${NAME} ${OBJS} ${BONUS_OBJS}

.PHONY: all clean fclean re bonus