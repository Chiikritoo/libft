# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: anchikri <anchikri@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/18 14:26:25 by anchikri          #+#    #+#              #
#    Updated: 2025/07/30 01:56:32 by anchikri         ###   ########.fr        #
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
				src/convert/ft_atof.c \
				src/convert/ft_atoll.c \
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
				src/print/printf/ft_vdprintf.c \
				src/print/printf/ft_vsnprintf.c \
				src/print/printf/handle_format.c \
				src/print/printf/append/append_char.c \
				src/print/printf/append/append_str.c \
				src/print/printf/append/append_int.c \
				src/print/printf/append/append_uint.c \
				src/print/printf/append/append_base.c \
				src/print/printf/append/append_ptr.c \

SRC_FREE =		src/free/ft_free_ptr.c \
				src/free/ft_free_double_ptr.c \

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
				src/memory/ft_memdup.c \
				src/memory/ft_memmove.c \
				src/memory/ft_memset.c \
				src/memory/ft_realloc.c

SRC_STRING =	src/string/ft_strchr.c \
				src/string/ft_strcmp.c \
				src/string/ft_strdup.c \
				src/string/ft_strcdup.c \
				src/string/ft_strndup.c \
				src/string/ft_strlcat.c \
				src/string/ft_strlcpy.c \
				src/string/ft_strlen.c \
				src/string/ft_strncmp.c \
				src/string/ft_strnstr.c \
				src/string/ft_strrchr.c \
				src/string/ft_strjoin.c \
				src/string/ft_strjoin_f1.c \
				src/string/ft_strjoin_f2.c \
				src/string/ft_strjoin_gnl.c \
				src/string/ft_strmapi.c \
				src/string/ft_strtrim.c \
				src/string/ft_substr.c \
				src/string/ft_split.c \
				src/string/ft_striteri.c \
				src/string/ft_strrev.c \
				src/string/ft_strtok.c \
				src/string/ft_strspn.c \
				src/string/ft_strcspn.c \
				src/string/ft_strpbrk.c

SRC_FILE =		src/file/ft_get_file.c \
				src/file/ft_file_size.c

SRC_TOML =		src/parser/toml/toml_parse_value.c \
				src/parser/toml/toml_parse_line.c \
				src/parser/toml/toml_parse_section.c \
				src/parser/toml/toml_parse_utils.c \
				src/parser/toml/toml_value_types.c \
				src/parser/toml/toml_array_parsing.c \
				src/parser/toml/toml_table_parsing.c \
				src/parser/toml/toml_string_utils.c \
				src/parser/toml/toml_file_init.c \
				src/parser/toml/toml_line_processing.c \
				src/parser/toml/toml_section_utils.c \
				src/parser/toml/toml_parse_file.c \
				src/parser/toml/toml_get_value.c \
				src/parser/toml/toml_helpers.c \
				src/parser/toml/toml_free.c

SRC_LOG =		src/log/init/log_init.c \
				src/log/levels/log_message.c \
				src/log/levels/log_info.c \
				src/log/levels/log_warning.c \
				src/log/levels/log_error.c \
				src/log/levels/log_debug.c \
				src/log/levels/log_level.c \
				src/log/format/log_prefix.c \
				src/log/io/log_fd.c \
				src/log/path/log_path.c \
				src/log/timestamp/log_timestamp.c \
				src/log/route/log_route.c \
				src/log/cleanup/log_cleanup.c

GC =			gc/garbage/gc_clear.c \
				gc/garbage/gc_free.c \
				gc/garbage/gc_ctx_destroy.c \
				gc/garbage/gc_ctx_init.c \
				gc/garbage/gc_node.c \
				gc/garbage/gc_hash.c \
				gc/garbage/gc_resize.c \
				gc/convert/gc_itoa.c \
				gc/convert/gc_utoa.c \
				gc/get_next_line/gc_get_next_line.c \
				gc/string/gc_strdup.c \
				gc/string/gc_strcdup.c \
				gc/string/gc_strndup.c \
				gc/string/gc_strjoin.c \
				gc/string/gc_strjoin_f1.c \
				gc/string/gc_strjoin_f2.c \
				gc/string/gc_strjoin_gnl.c \
				gc/string/gc_strtrim.c \
				gc/string/gc_substr.c \
				gc/string/gc_split.c \
				gc/memory/gc_calloc.c \
				gc/memory/gc_realloc.c

SRC =			$(SRC_CORE) \
				$(SRC_ERROR) \
				$(SRC_CHECK) \
				$(SRC_CONVERT) \
				$(SRC_PRINT) \
				$(SRC_FREE) \
				$(SRC_GNL) \
				$(SRC_LIST) \
				$(SRC_MEMORY) \
				$(SRC_STRING) \
				$(SRC_LOG) \
				$(SRC_FILE) \
				$(SRC_TOML) \
				$(SRC_MATH) \
				$(SRC_VECTOR) \
				$(GC)

BUILD =			build/

OBJ =			$(SRC:%.c=$(BUILD)%.o)
DEPS =			$(SRC:%.c=$(BUILD)%.d)

# ==================== FLAGS ==================== #

CC = cc
CFLAGS = -Wall -Werror -Wextra -Iinclude -g3
DEPFLAGS = -MMD -MP
RM = rm -rf
AR = ar rcs

# ==================== COUNTER ==================== #

COUNTER = 0
TOTAL = $(words $(SRC))

# ==================== RULES ==================== #

all: $(NAME)

$(BUILD)%.o: %.c 
	@mkdir -p $(@D)
	$(eval COUNTER := $(shell echo $$(($(COUNTER)+1))))
	@printf "$(GREEN)[$(COUNTER)/$(TOTAL) - %d%%]$(RESET) $(CYAN)Compiling:$(RESET) $<\n" $$(($(COUNTER) * 100 / $(TOTAL)))
	@$(CC) $(CFLAGS) $(DEPFLAGS) -c $< -o $@

$(NAME): $(OBJ) 
	@mkdir -p bin
	@printf "$(GREEN)Creating static library...$(RESET)\n"
	@$(AR) $(NAME) $(OBJ)
	@mv $(NAME) bin
	@echo "$(GREEN)✓$(RESET) $(BOLD)Static library created:$(RESET) $(CYAN)bin/$(NAME)$(RESET)"

clean:
	@printf "$(YELLOW)Cleaning object files...$(RESET)\n"
	@$(RM) $(BUILD)
	@echo "$(GREEN)✓$(RESET) $(BOLD)Object files deleted$(RESET)"

fclean:	clean
	@printf "$(YELLOW)Cleaning binaries...$(RESET)\n"
	@$(RM) bin
	@echo "$(GREEN)✓$(RESET) $(BOLD)All binaries deleted$(RESET)"

re:		fclean all

.PHONY: all clean fclean re bonus test_toml

# ==================== DEPENDENCIES ==================== #

-include $(DEPS)

# ==================== COLORS ==================== #

GREEN = \033[0;32m
CYAN = \033[0;36m
YELLOW = \033[0;33m
RED = \033[0;31m
BOLD = \033[1m
RESET = \033[0m
