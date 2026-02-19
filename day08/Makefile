##
## EPITECH PROJECT, 2024
## __
## File description:
## ./Makefile
##

MAKEFLAGS += -j

SRC := AFruit.cpp IFruit.cpp ACitrus.cpp ABerry.cpp ANut.cpp \
       Lemon.cpp Orange.cpp Strawberry.cpp Almond.cpp \
       Grapefruit.cpp BloodOrange.cpp Raspberry.cpp Coconut.cpp \
       FruitBox.cpp FruitUtils.cpp FruitFactory.cpp FruitMixer.cpp

SRC_TEST := tests/tests.cpp
SRC_TEST += $(SRC)

BIN_NAME_TEST := unit_tests

BUILD_DIR := .build

CC := g++

CFLAGS += -Wall -Wextra -Werror
CFLAGS += -std=c++20
CFLAGS += -Wno-unused-parameter

include utils.mk

.PHONY: _start all
_start: all

define mk-profile

NAME_$(strip $1) := $4
OBJ_$(strip $1) := $$($(strip $2):%.cpp=$$(BUILD_DIR)/$(strip $1)/%.o)

$$(BUILD_DIR)/$(strip $1)/%.o: %.cpp
	@ mkdir -p $$(dir $$@)
	@ $$(COMPILE.cpp) $$< -o $$@ $(strip $3)
	@ $$(LOG_TIME) "$$(C_GREEN) CC $$(C_PURPLE) $$(notdir $$@) $$(C_RESET)"

$$(NAME_$(strip $1)): $$(OBJ_$(strip $1))
	@ $$(LINK.cpp) $$(OBJ_$(strip $1)) $(strip $3) -o $$@
	@ $$(LOG_TIME) "$$(C_CYAN) LD $$(C_PURPLE) $$(notdir $$@) $$(C_RESET)"

endef

$(eval $(call mk-profile, testcrit, SRC_TEST, --coverage -lcriterion, $(BIN_NAME_TEST)))

all:
	@ echo

.PHONY: tests_run
tests_run: $(NAME_testcrit)
	@ ./$(BIN_NAME_TEST)

.PHONY: cov
cov: tests_run
	@ gcovr . \
		--gcov-ignore-errors=no_working_dir_found \
		--exclude-unreachable-branches \
		--exclude tests/

clean:
	@ $(RM) -r $(BUILD_DIR) *.gcno *.gcda tmp
	@ $(LOG_TIME) "$(C_YELLOW) RM $(C_PURPLE) $(BUILD_DIR) *.gcno *.gcda tmp $(C_RESET)"

fclean: clean
	@ $(RM) $(BIN_NAME_TEST)
	@ $(LOG_TIME) "$(C_YELLOW) RM $(C_PURPLE) $(BIN_NAME_TEST) $(C_RESET)"

.NOTPARALLEL: re
re:	fclean all

.PHONY: all clean fclean re tests_run cov
