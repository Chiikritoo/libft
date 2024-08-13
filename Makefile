# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: anchikri <anchikri@student.42mulhouse.f    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/18 14:26:25 by anchikri          #+#    #+#              #
#    Updated: 2024/08/13 03:53:44 by anchikri         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

# ==================== SOURCES ==================== #

SRC_CHECK =		src/check/ft_isalnum.c \
				src/check/ft_isalpha.c \
				src/check/ft_isascii.c \
				src/check/ft_isdigit.c \
				src/check/ft_isprint.c

SRC_CONVERT =	src/convert/ft_atoi.c \
				src/convert/ft_itoa.c \
				src/convert/ft_toupper.c \
				src/convert/ft_tolower.c

SRC_FD =		src/fd/ft_putchar_fd.c \
				src/fd/ft_putendl_fd.c \
				src/fd/ft_putnbr_fd.c \
				src/fd/ft_putstr_fd.c

SRC_FREE =		src/free/ft_free_ptr.c \
				src/free/ft_free_double_ptr.c \
				src/free/ft_free_triple_ptr.c

SRC_DPRINTF =	src/ft_dprintf/ft_dprintf.c \
				src/ft_dprintf/ft_dprint_nbr.c \
				src/ft_dprintf/ft_dprint.c

SRC_PRINTF =	src/ft_printf/ft_printf.c \
				src/ft_printf/ft_print_nbr.c \
				src/ft_printf/ft_print.c

SRC_GARBAGE =	src/garbage/ft_clear_garbage.c \
				src/garbage/ft_garbage.c \
				src/garbage/ft_gc_calloc.c

SRC_GNL =		src/get_next_line/get_next_line.c \

SRC_LIST =		src/list/ft_lstnew_bonus.c \
				src/list/ft_lstadd_front_bonus.c \
				src/list/ft_lstsize_bonus.c \
				src/list/ft_lstlast_bonus.c \
				src/list/ft_lstadd_back_bonus.c \
				src/list/ft_lstdelone_bonus.c \
				src/list/ft_lstclear_bonus.c \
				src/list/ft_lstiter_bonus.c \
				src/list/ft_lstmap_bonus.c

SRC_MEMORY =	src/memory/ft_bzero.c \
				src/memory/ft_calloc.c \
				src/memory/ft_memchr.c \
				src/memory/ft_memcmp.c \
				src/memory/ft_memcpy.c \
				src/memory/ft_memmove.c \
				src/memory/ft_memset.c \
				src/memory/ft_realloc.c

SRC_STRING =	src/string/ft_strchr.c \
				src/string/ft_strcmp.c \
				src/string/ft_strdup.c \
				src/string/ft_strlcat.c \
				src/string/ft_strlcpy.c \
				src/string/ft_strlen.c \
				src/string/ft_strncmp.c \
				src/string/ft_strnstr.c \
				src/string/ft_strrchr.c \
				src/string/ft_strjoin.c \
				src/string/ft_strjoin_gnl.c \
				src/string/ft_strmapi.c \
				src/string/ft_strtrim.c \
				src/string/ft_substr.c \
				src/string/ft_split.c \
				src/string/ft_striteri.c

src =			${SRC_CHECK} \
				${SRC_CONVERT} \
				${SRC_FD} \
				${SRC_FREE} \
				${SRC_DPRINTF} \
				${SRC_PRINTF} \
				${SRC_GNL} \
				${SRC_GARBAGE} \
				${SRC_LIST} \
				${SRC_MEMORY} \
				${SRC_STRING}

OBJDIR =		build/

OBJS =			${src:%.c=${OBJDIR}%.o}

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
	@mkdir -p bin
	@${AR} ${NAME} ${OBJS}
	@mv ${NAME} bin
	@echo "\n${CYAN}${NAME} ${GREEN}has been created${RESET}"

clean:
	@${RM} ${OBJDIR}
	@echo "${YELLOW}objs ${RED}deleted${RESET}"

fclean:	clean
	@${RM} bin
	@echo "${CYAN}${NAME} ${RED}deleted${RESET}"

re:		fclean all

.PHONY: all clean fclean re bonus

# ==================== COLORS ==================== #

GREEN = \033[0;32m
CYAN = \033[0;36m
YELLOW = \033[0;33m
RED = \033[0;31m
RESET = \033[0m
