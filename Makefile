# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: anchikri <anchikri@student.42mulhouse.f    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/18 14:26:25 by anchikri          #+#    #+#              #
#    Updated: 2024/08/15 20:19:25 by anchikri         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

# ==================== SOURCES ==================== #

SRC_CHECK =		src/check/ft_isalnum.c \
				src/check/ft_isalpha.c \
				src/check/ft_isascii.c \
				src/check/ft_isdigit.c \
				src/check/ft_isprint.c \
				src/check/ft_isspace.c \

SRC_CONVERT =	src/convert/ft_atoi.c \
				src/convert/ft_itoa.c \
				src/convert/ft_toupper.c \
				src/convert/ft_tolower.c \
				src/convert/ft_utoa.c \

SRC_PRINT =		src/print/ft_putchar_fd.c \
				src/print/ft_putendl_fd.c \
				src/print/ft_putnbr_fd.c \
				src/print/ft_putstr_fd.c \
				src/print/printf/ft_printf.c \
				src/print/printf/ft_dprintf.c \
				src/print/printf/handle_format.c \
				src/print/printf/append/append_char.c \
				src/print/printf/append/append_str.c \
				src/print/printf/append/append_int.c \
				src/print/printf/append/append_uint.c \
				src/print/printf/append/append_base.c \
				src/print/printf/append/append_ptr.c \

SRC_FREE =		src/free/ft_free_ptr.c \
				src/free/ft_free_double_ptr.c \
				src/free/ft_free_triple_ptr.c

SRC_GARBAGE =	src/garbage/gc_malloc.c \
				src/garbage/gc_clear.c \
				src/garbage/gc_free.c \
				src/garbage/gc_ctx_destroy.c \
				src/garbage/gc_ctx_init.c \

SRC_GNL =		src/get_next_line/get_next_line.c \

SRC_LIST =		src/list/ft_lstnew.c \
				src/list/ft_lstadd_front.c \
				src/list/ft_lstsize.c \
				src/list/ft_lstlast.c \
				src/list/ft_lstadd_back.c \
				src/list/ft_lstdelone.c \
				src/list/ft_lstclear.c \
				src/list/ft_lstiter.c \
				src/list/ft_lstmap.c \
				src/list/ft_ctx_init.c \
				src/list/ft_ctx_destroy.c

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
				src/string/ft_strjoin_free.c \
				src/string/ft_strmapi.c \
				src/string/ft_strtrim.c \
				src/string/ft_substr.c \
				src/string/ft_split.c \
				src/string/ft_striteri.c

SRC_GC =		src_gc/convert/gc_itoa.c \
				src_gc/convert/gc_utoa.c \
				src_gc/get_next_line/gc_get_next_line.c \
				src_gc/string/gc_strdup.c \
				src_gc/string/gc_strjoin.c \
				src_gc/string/gc_strjoin_free.c \
				src_gc/string/gc_strtrim.c \
				src_gc/string/gc_substr.c \
				src_gc/string/gc_split.c \
				src_gc/memory/gc_calloc.c \
				src_gc/memory/gc_realloc.c

src =			${SRC_CHECK} \
				${SRC_CONVERT} \
				${SRC_PRINT} \
				${SRC_FREE} \
				${SRC_PRINTF} \
				${SRC_GNL} \
				${SRC_GARBAGE} \
				${SRC_LIST} \
				${SRC_MEMORY} \
				${SRC_STRING} \
				${SRC_GC}

OBJDIR =		build/

OBJS =			${src:%.c=${OBJDIR}%.o}

# ==================== FLAGS ==================== #

CC = cc
CFLAGS = -Wall -Werror -Wextra -g3
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
