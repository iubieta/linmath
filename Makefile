##
# Lib LINNMATH
#
# @file
# @version 0.1

NAME = liblinmath
CC = gcc
CFLAGS	= -Wall -Werror -Wextra
TESTS_LDFLAGS= -L. -llinmath -lcriterion -lm -pthread

RELEASE_OBJ_DIR=obj/
TEST_OBJ_DIR=test/obj
TEST_BIN_DIR=test/bin

RELEASE_SRC=$(wildcard src/*.c)
RELEASE_OBJ=$(subst src/,obj/,$(RELEASE_SRC:.c=.o))

# TESTS_SRC=$(shell find test/src/ -type f -name '*.c')
# TESTS_OBJ=$(patsubst test/src/,test/obj/,$(TESTS_SRC:.c=.o))
# TESTS_BIN=$(patsubst test/src/,tests/bin/,$(TESTS_SRC:.c=))

TESTS_SRC    := $(wildcard test/src/*.c)
TESTS_OBJ    := $(TESTS_SRC:test/src/%.c=$(TEST_OBJ_DIR)/%.o)
TESTS_BIN    := $(TESTS_SRC:test/src/%.c=$(TEST_BIN_DIR)/%)

HEADERS = src/$(NAME).h
RM = rm -f

# Colors
DEF_COLOR = \033[0;39m
GRAY = \033[0;90m
RED = \033[0;91m
GREEN = \033[0;92m
YELLOW = \033[0;93m
BLUE = \033[0;94m
MAGENTA = \033[0;95m
CYAN = \033[0;96m
WHITE = \033[0;97m


all: $(NAME)
	@echo "liblinmath compiled"

$(NAME): $(RELEASE_OBJ)
	@ar rcs $(NAME).a $(RELEASE_OBJ)

$(RELEASE_OBJ_DIR)%.o: src/%.c | $(RELEASE_OBJ_DIR)
	@$(CC) $(CFLAGS) -c $^ -o $@
	@echo "release objects created"

$(TEST_OBJ_DIR)/%.o: test/src/%.c | $(TEST_OBJ_DIR)
	@$(CC) $(CFLAGS) -c $^ -o $@
	@echo "test objects created"

$(TEST_BIN_DIR)/%: test/obj/%.o $(NAME) $(HEADERS) | $(TEST_OBJ_DIR) $(TEST_BIN_DIR)
	@$(CC) $(TESTS_LDFLAGS) $^ -o $@
	@echo "test binaries created"

$(RELEASE_OBJ_DIR):
	mkdir -p $@

$(TEST_OBJ_DIR):
	mkdir -p $@

$(TEST_BIN_DIR):
	mkdir -p $@

# prevent deleting object in rules chain
#$(TESTS_BIN): $(RELEASE_OBJ) $(TESTS_OBJ) # no descomentar

run-tests: $(TESTS_BIN)
	@./$^ || true

clean:
	@$(RM) -rf $(RELEASE_OBJ)
	@$(RM) -rf $(TESTS_OBJ)
	@$(RM) -f src/$(NAME).h.gch
	@echo "$(BLUE)$(NAME) test object files succesfully cleaned!$(DEF_COLOR)"

fclean: clean
	@$(RM) $(TESTS_BIN_DIR)
	@echo "$(CYAN)$(NAME) test executable files succesfully cleaned!$(DEF_COLOR)"
	@$(RM) $(NAME).a
	@echo "$(CYAN)$(NAME) library file succesfully cleaned!$(DEF_COLOR)"

re: fclean all

.PHONY: all clean fclean re

# end
