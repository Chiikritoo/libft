# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: anchikri <anchikri@student.42mulhouse.f    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/18 14:26:25 by anchikri          #+#    #+#              #
#    Updated: 2024/06/12 23:25:39 by anchikri         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

# ==================== SOURCES ==================== #

SRC_CHECK =		srcs/check/ft_isalnum.c \
				srcs/check/ft_isalpha.c \
				srcs/check/ft_isascii.c \
				srcs/check/ft_isdigit.c \
				srcs/check/ft_isprint.c

SRC_CONVERT =	srcs/convert/ft_atoi.c \
				srcs/convert/ft_itoa.c \
				srcs/convert/ft_toupper.c \
				srcs/convert/ft_tolower.c

SRC_FD =		srcs/fd/ft_putchar_fd.c \
				srcs/fd/ft_putendl_fd.c \
				srcs/fd/ft_putnbr_fd.c \
				srcs/fd/ft_putstr_fd.c

SRC_FREE =		srcs/free/ft_free_ptr.c \
				srcs/free/ft_free_double_ptr.c \
				srcs/free/ft_free_triple_ptr.c

SRC_FPRINTF =	srcs/ft_fprintf/ft_fprintf.c \
				srcs/ft_fprintf/ft_fprint_nbr.c \
				srcs/ft_fprintf/ft_fprint.c

SRC_PRINTF =	srcs/ft_printf/ft_printf.c \
				srcs/ft_printf/ft_print_nbr.c \
				srcs/ft_printf/ft_print.c

SRC_GARBAGE =	srcs/garbage/ft_clear_garbage.c \
				srcs/garbage/ft_garbage.c \
				srcs/garbage/ft_gc_calloc.c

SRC_GNL =		srcs/get_next_line/get_next_line.c \
				srcs/get_next_line/get_next_line_utils.c

SRC_LIST =		srcs/list/ft_lstnew_bonus.c \
				srcs/list/ft_lstadd_front_bonus.c \
				srcs/list/ft_lstsize_bonus.c \
				srcs/list/ft_lstlast_bonus.c \
				srcs/list/ft_lstadd_back_bonus.c \
				srcs/list/ft_lstdelone_bonus.c \
				srcs/list/ft_lstclear_bonus.c \
				srcs/list/ft_lstiter_bonus.c \
				srcs/list/ft_lstmap_bonus.c

SRC_MEMORY =	srcs/memory/ft_bzero.c \
				srcs/memory/ft_calloc.c \
				srcs/memory/ft_memchr.c \
				srcs/memory/ft_memcmp.c \
				srcs/memory/ft_memcpy.c \
				srcs/memory/ft_memmove.c \
				srcs/memory/ft_memset.c \
				srcs/memory/ft_realloc.c

SRC_STRING =	srcs/string/ft_strchr.c \
				srcs/string/ft_strcmp.c \
				srcs/string/ft_strdup.c \
				srcs/string/ft_strlcat.c \
				srcs/string/ft_strlcpy.c \
				srcs/string/ft_strlen.c \
				srcs/string/ft_strncmp.c \
				srcs/string/ft_strnstr.c \
				srcs/string/ft_strrchr.c \
				srcs/string/ft_strjoin.c \
				srcs/string/ft_strmapi.c \
				srcs/string/ft_strtrim.c \
				srcs/string/ft_substr.c \
				srcs/string/ft_split.c \
				srcs/string/ft_striteri.c

SRCS =			${SRC_CHECK} \
				${SRC_CONVERT} \
				${SRC_FD} \
				${SRC_FREE} \
				${SRC_FPRINTF} \
				${SRC_PRINTF} \
				${SRC_GNL} \
				${SRC_GARBAGE} \
				${SRC_LIST} \
				${SRC_MEMORY} \
				${SRC_STRING}

OBJDIR =		.objs/

OBJS =			${SRCS:%.c=${OBJDIR}%.o}

# ==================== FLAGS ==================== #

CC = cc
CFLAGS = -Wall -Werror -Wextra -fsanitize=address -g
RM = rm -rf
AR = ar rcs

# ==================== RULES ==================== #

all: ${NAME}

${OBJDIR}%.o: %.c 
	@mkdir -p ${@D}
	@${CC} ${CFLAGS} -c $< -o $@
	@echo -n "${GREEN}Compiling ${CYAN}${NAME}${RESET}...\r"

${NAME}: ${OBJS} 
	@${AR} ${NAME} ${OBJS}
	@echo "\n${CYAN}${NAME} ${GREEN}has been created${RESET}"

clean:
	@${RM} ${OBJDIR}
	@echo "${YELLOW}objs ${RED}deleted${RESET}"

fclean:	clean
	@${RM} ${NAME}
	@echo "${CYAN}${NAME} ${RED}deleted${RESET}"

re:		fclean all

.PHONY: all clean fclean re bonus

# ==================== COLORS ==================== #

GREEN = \033[0;32m
CYAN = \033[0;36m
YELLOW = \033[0;33m
RED = \033[0;31m
RESET = \033[0m
