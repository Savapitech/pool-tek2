##
## EPITECH PROJECT, 2024
## __
## File description:
## ./Makefile
##

MAKEFLAGS += -j

BIN_NAME := z

SRC := $(wildcard *.c)

BUILD_DIR := .build

CC := clang

CFLAGS += -Wall -Wextra -Werror=write-strings
CFLAGS += -std=gnu17
CFLAGS += -Wno-unused-parameter -Wunused-result
CFLAGS += -Wcast-qual -Wformat=2 -Wshadow -fno-builtin
CFLAGS += -Wstrict-aliasing=0 -Wstrict-prototypes -Wunreachable-code
CFLAGS += -Wwrite-strings -Werror=declaration-after-statement
CFLAGS += -Werror=format-nonliteral -Werror=int-conversion -Werror=return-type

include utils.mk

.PHONY: _start all
_start: all

# call mk-profile release, SRC, additional CFLAGS
define mk-profile

NAME_$(strip $1) := $4
OBJ_$(strip $1) := $$($(strip $2):%.c=$$(BUILD_DIR)/$(strip $1)/%.o)

$$(BUILD_DIR)/$(strip $1)/%.o: %.c
	@ mkdir -p $$(dir $$@)
	@ $$(COMPILE.c) $$< -o $$@
	@ $$(LOG_TIME) "$$(C_GREEN) CC $$(C_PURPLE) $$(notdir $$@) $$(C_RESET)"

$$(NAME_$(strip $1)): $$(LIB_NAME_$(strip $1)) $$(OBJ_$(strip $1))
	@ $$(LINK.c) $$(OBJ_$(strip $1)) $$(LDFLAGS) $$(LDLIBS) -o $$@
	@ $$(LOG_TIME) "$$(C_YELLOW) LD $$(C_PURPLE) $$(notdir $$@) $$(C_RESET)"
	@ $$(LOG_TIME) "$$(C_GREEN) OK  Compilation finished $$(C_RESET)"

endef

$(eval $(call mk-profile, release, SRC, -iquote src -g3, $(BIN_NAME)))

all: $(NAME_release)

clean:
	@ $(RM) $(OBJ)
	@ $(LOG_TIME) "$(C_YELLOW) RM $(C_PURPLE) $(OBJ) $(C_RESET)"

fclean:
	@ $(RM) -r $(NAME_release) $(NAME_debug) $(BUILD_DIR)
	@ $(LOG_TIME) "$(C_YELLOW) RM $(C_PURPLE) $(NAME_release) $(NAME_debug) \
		$(C_RESET)"

.NOTPARALLEL: re
re:	fclean all

.PHONY: all clean fclean re
