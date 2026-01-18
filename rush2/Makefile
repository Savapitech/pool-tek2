##
## EPITECH PROJECT, 2024
## __
## File description:
## ./Makefile
##

MAKEFLAGS += -j

BIN_NAME := pushswap_checker

SRC := pushswap_checker.hs

CC := ghc

include utils.mk

.PHONY: _start all
_start: all

# call mk-profile release, SRC, additional CFLAGS
define mk-profile

NAME_$(strip $1) := $4

$$(NAME_$(strip $1)):
	@ $$(CC) $$(SRC) -o $4
	@ $$(LOG_TIME) "$$(C_CYAN) GHC $$(C_PURPLE) $$(notdir $$@) $$(C_RESET)"
	@ $$(LOG_TIME) "$$(C_GREEN) OK  Compilation finished $$(C_RESET)"

endef

$(eval $(call mk-profile, release, SRC,, $(BIN_NAME)))

all: $(NAME_release)

clean:
	@ $(RM) *.hi *.o
	@ $(LOG_TIME) "$(C_YELLOW) RM $(C_PURPLE) *.hi *.o $(C_RESET)"

fclean:
	@ $(RM) *.hi *.o
	@ $(RM) -r $(NAME_release) $(NAME_debug) $(BUILD_DIR)
	@ $(LOG_TIME) "$(C_YELLOW) RM $(C_PURPLE) $(NAME_release) $(NAME_debug) \
		$(C_RESET)"

.NOTPARALLEL: re
re:	fclean all

.PHONY: all clean fclean re
