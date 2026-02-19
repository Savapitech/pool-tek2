MAKEFLAGS += -j

BIN_NAME := bistroMatic

SRC = $(SRC_WITHOUT_MAIN)
SRC += src/main.cpp

SRC_WITHOUT_MAIN = 	src/Instructions.cpp \
					src/Operand.cpp \
					src/OperandFactory.cpp \
					src/VirtualMachine.cpp

BUILD_DIR := .build

CC := clang++

CFLAGS += -Wall -Wextra -Werror=write-strings
CFLAGS += -std=c++20 -iquote src
CFLAGS += -Wno-unused-parameter
CFLAGS += -Wcast-qual -Wformat=2 -Wshadow -fno-builtin
CFLAGS += -Wstrict-aliasing=0 -Wstrict-prototypes -Wunreachable-code
CFLAGS += -Wwrite-strings -Werror=declaration-after-statement
CFLAGS += -Werror=format-nonliteral -Werror=int-conversion -Werror=return-type

SRC_TEST = tests/UT_Instruction.cpp
SRC_TEST += tests/UT_division.cpp
SRC_TEST += $(SRC_WITHOUT_MAIN)

BIN_NAME_TEST := unit_test

include utils.mk

.PHONY: _start all
_start: all

# call mk-profile release, SRC, additional CFLAGS
define mk-profile

NAME_$(strip $1) := $4
OBJ_$(strip $1) := $$($(strip $2):%.cpp=$$(BUILD_DIR)/$(strip $1)/%.o)

$$(BUILD_DIR)/$(strip $1)/%.o: %.cpp
	@ mkdir -p $$(dir $$@)
	@ $$(COMPILE.cpp) $$< -o $$@ $(strip $3)
	@ $$(LOG_TIME) "$$(C_GREEN) CC $$(C_PURPLE) $$(notdir $$@) $$(C_RESET)"

$$(NAME_$(strip $1)): $$(LIB_NAME_$(strip $1)) $$(OBJ_$(strip $1))
	@ $$(LINK.cpp) $$(OBJ_$(strip $1)) $(strip $3) -o $$@
	@ $$(LOG_TIME) "$$(C_CYAN) LD $$(C_PURPLE) $$(notdir $$@) $$(C_RESET)"
	@ $$(LOG_TIME) "$$(C_GREEN) OK  Compilation finished $$(C_RESET)"

endef

$(eval $(call mk-profile, release, SRC,, $(BIN_NAME)))
$(eval $(call mk-profile, test, SRC, --coverage, test))
$(eval $(call mk-profile, testcrit, SRC_TEST, --coverage -lcriterion, $(BIN_NAME_TEST)))

all: $(NAME_release)

.PHONY: tests_run
tests_run: $(NAME_testcrit) $(NAME_test)
	@ bash tests/test.sh
	@ ./unit_test

.PHONY: cov
cov: tests_run
	gcovr . \
		--gcov-ignore-errors=no_working_dir_found \
		--exclude-unreachable-branches \
		--exclude tests/

format:
	@ clang-format -i src/*
	@ $(LOG_TIME) "$(C_GREEN) OK  Code formated  $(C_RESET)"

clean:
	@ $(RM) $(OBJ)
	@ $(LOG_TIME) "$(C_YELLOW) RM $(C_PURPLE) $(OBJ) $(C_RESET)"

fclean:
	@ $(RM) -r $(NAME_release) $(NAME_debug) $(BUILD_DIR)
	@ $(LOG_TIME) "$(C_YELLOW) RM $(C_PURPLE) $(NAME_release) $(NAME_test) \
		$(C_RESET)"

.NOTPARALLEL: re
re:	fclean all

.PHONY: all clean fclean re
