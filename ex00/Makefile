# Verbose control
VERBOSE = 0
ifeq ($(VERBOSE),1)
	SILENT =
	DUMP_OUT =
else
	SILENT = @
	DUMP_OUT = > /dev/null 2>&1
endif

CC = c++
NAME = zombie_simulator
CFLAGS = -Wall -Werror -Wextra -std=c++98

BIN_DIR = ./
SRC_DIR = ./
OBJ_DIR = .obj

SRC = newZombie.cpp randomChump.cpp Zombie.cpp main.cpp

OBJ = $(SRC:%.cpp=$(OBJ_DIR)/%.o)
DEP = $(OBJ:.o=.d)

all: $(BIN_DIR)/$(NAME)

$(BIN_DIR)/$(NAME): $(OBJ)
	$(SILENT)mkdir -p $(BIN_DIR)
	$(CC) $(CFLAGS) -MMD -MP -o $@ $(OBJ)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp Makefile
	$(SILENT)mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -MMD -MP -c $< -o $@

clean:
	$(SILENT)rm -rf $(OBJ_DIR)

fclean: clean
	$(SILENT)rm -f $(BIN_DIR)/$(NAME)

re: fclean all

-include $(DEP)

.PHONY: all clean fclean re