NAME = push_swap
BONUS_NAME = checker
CFLAGS = -Wall -Werror -Wextra -g3

# Paths for libraries
LIB_PATH = libft
LIB_NAME = libft/libft.a
LINCLUDES = -L $(LIB_PATH) -lft

# Colors Definition
GREEN = "\033[32;1m"
RED = "\033[31;1m"

# Paths
SRC = src
INC = includes
OBJ = obj

# files path
MANDATORY = $(SRC)/mandatory
BONUS = $(SRC)/bonus

# Main
MAIN_SRC = $(MANDATORY)/push_swap.c
BONUS_SRC = $(addprefix $(BONUS)/, checker_bonus.c)

CFILES = $(addprefix $(MANDATORY)/, deal_with_args.c \
			error.c finding.c linked_list.c push.c \
			push_swap_utils.c rotate.c send_to.c swap.c)

OBJECT = $(CFILES:%.c=$(OBJ)/%.o)
BIN_OBJ = $(MAIN_SRC:%.c=$(OBJ)/%.o)

# define bonus #
ifdef WITH_BONUS
	NAME = $(BONUS_NAME)
	MAIN_SRC = $(BONUS_SRC)
	BIN_OBJ = $(BONUS_SRC:%.c=$(OBJ)/%.o)
endif

define create_objects_dir
	@mkdir -p $(dir $@)
endef

define compile
	@$(CC) -o $(NAME) $(CFLAGS) $(INCLUDES) $(LINCLUDES) $(OBJECT) $(BIN_OBJ) $(LIB_NAME)
	@echo $(GREEN)[Read to use]$(COLOR_LIMITER)
endef

define compile_bonus
	@$(CC) -o $(NAME) $(CFLAGS) $(INCLUDES) $(LINCLUDES) $(OBJECT) $(BIN_OBJ) $(LIB_NAME)
endef

define compile_source
	@$(CC) -o $@ $(CFLAGS) $(INCLUDES) -c $< 
endef

define make_lib
	@$(MAKE) -sC $(LIB_PATH)
endef
define bonus
	@make WITH_BONUS=TRUE -s
endef

all: $(NAME)

$(NAME): $(OBJECT) $(BIN_OBJ)
	$(call create_objects_dir)
	$(call make_lib)
	$(call compile)

$(OBJ)/%.o: %.c
	$(call create_objects_dir)
	$(call compile_source)

bonus:
	$(call bonus)

test3:		$(NAME)
		$(eval ARG = $(shell shuf -i 0-3 -n 3))
		./push_swap $(ARG) | ./checker_linux $(ARG)
		@echo -n "Instructions: "
		@./push_swap $(ARG) | wc -l

test5:		$(NAME)
		$(eval ARG = $(shell shuf -i 0-5 -n 5))
		./push_swap $(ARG) | ./checker_linux $(ARG)
		@echo -n "Instructions: "
		@./push_swap $(ARG) | wc -l

test10:		$(NAME)
		$(eval ARG = $(shell shuf -i 0-9 -n 10))
		./push_swap $(ARG) | ./checker_linux $(ARG)
		@echo -n "Instructions: "
		@./push_swap $(ARG) | wc -l

test100:	$(NAME)
		$(eval ARG = $(shell shuf -i 0-1000 -n 100))
		./push_swap $(ARG) | ./checker_linux $(ARG)
		@echo -n "Instructions: "
		@./push_swap $(ARG) | wc -l

test500:	$(NAME)
		$(eval ARG = $(shell shuf -i 0-1000 -n 500))
		./push_swap $(ARG) | ./checker_linux $(ARG)
		@echo -n "Instructions: "
		@./push_swap $(ARG) | wc -l

clean:
	@echo $(RED)[Removing Objects]$(COLOR_LIMITER)
	@rm -rf $(LIB_PATH)/$(LIB_NAME)
	@rm -rf $(OBJ)

fclean: clean fclean_bonus
	@echo $(RED)[Removing $(NAME) executable]$(COLOR_LIMITER)
	@make fclean -C $(LIB_PATH) --no-print-directory
	@rm -rf $(NAME)

fclean_bonus:
ifneq ($(wildcard $(BONUS_NAME)),)
	@echo $(RED)[Removing $(BONUS_NAME) executable]$(COLOR_LIMITER)
	@rm -rf $(BONUS_NAME)
endif

re: fclean
	@make --no-print-directory

.PHONY: all clean fclean re libft bonus
.DEFAULT_GOAL := all