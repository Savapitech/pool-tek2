MAKEFLAGS += -j

BIN_NAME := MyGKrellm

SRC = src/main.cpp
SRC += src/modules/AModule.cpp
SRC += src/modules/ModuleSystemInfo.cpp
SRC += src/modules/ModuleCpuInfo.cpp
SRC += src/modules/ModuleRamInfo.cpp
SRC += src/modules/ModuleBatteryInfo.cpp
SRC += src/modules/ModuleNetworkInfo.cpp
SRC += src/Metrics.cpp
SRC += src/display/sfml/SFML.cpp
SRC += src/display/ncurses/Ncurses.cpp

BUILD_DIR := .build

CXX := clang++

CXXFLAGS += -Wall -Wextra -Werror=write-strings
CXXFLAGS += -std=c++20 -iquote src
CXXFLAGS += -Wno-unused-parameter
CXXFLAGS += -Wcast-qual -Wformat=2 -Wshadow -fno-builtin
CXXFLAGS += -Wstrict-aliasing=0 -Wstrict-prototypes -Wunreachable-code
CXXFLAGS += -Wwrite-strings -Werror=declaration-after-statement
CXXFLAGS += -Werror=format-nonliteral -Werror=int-conversion -Werror=return-type

LDFLAGS += -lncurses -lsfml-graphics -lsfml-window -lsfml-system

include utils.mk

.PHONY: _start all
_start: all

# call mk-profile release, SRC, additional CFLAGS
define mk-profile

NAME_$(strip $1) := $4
OBJ_$(strip $1) := $$($(strip $2):%.cpp=$$(BUILD_DIR)/$(strip $1)/%.o)

$$(BUILD_DIR)/$(strip $1)/%.o: %.cpp
	@ mkdir -p $$(dir $$@)
	@ $$(COMPILE.cpp) $$< -o $$@ $$(CXXFLAGS) $(strip $3)
	@ $$(LOG_TIME) "$$(C_GREEN) CC $$(C_PURPLE) $$(notdir $$@) $$(C_RESET)"

$$(NAME_$(strip $1)): $$(LIB_NAME_$(strip $1)) $$(OBJ_$(strip $1))
	@ $$(LINK.cpp) $$(OBJ_$(strip $1)) $$(LDFLAGS) $(strip $3) -o $$@
	@ $$(LOG_TIME) "$$(C_CYAN) LD $$(C_PURPLE) $$(notdir $$@) $$(C_RESET)"
	@ $$(LOG_TIME) "$$(C_GREEN) OK  Compilation finished $$(C_RESET)"

endef

$(eval $(call mk-profile, release, SRC,, $(BIN_NAME)))
$(eval $(call mk-profile, test, SRC, --coverage, test))

all: $(NAME_release)

format:
	@ clang-format -i $(SRC) src/*.hpp src/modules/*.hpp \
		src/display/sfml/*.hpp \
		src/display/ncurses/*.hpp
	@ $(LOG_TIME) "$(C_BLUE) CF $(C_GREEN) Code formated  $(C_RESET)"

clean:
	@ $(RM) $(OBJ)
	@ $(LOG_TIME) "$(C_YELLOW) RM $(C_PURPLE) $(OBJ) $(C_RESET)"

fclean:
	@ $(RM) -r $(NAME_release) $(NAME_debug) $(BUILD_DIR)
	@ $(LOG_TIME) "$(C_YELLOW) RM $(C_PURPLE) $(NAME_release) \
		$(C_RESET)"

.NOTPARALLEL: re
re:	fclean all

.PHONY: all clean fclean re
