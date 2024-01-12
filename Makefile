NAME		:= push_swap
CC			:= gcc
FLAGS		:= -Wall -Wextra -Werror -g3
BIN			:= ./bin/
SRCS		:= $(addprefix ./src/mandatory/, push_swap.c linked_list.c \
					error.c deal_with_args.c rotate.c swap.c \
					push_swap_utils.c finding.c push.c send_to.c)
OBJS		:= $(patsubst ./src/mandatory/%.c,$(BIN)%.o,$(SRCS))
LIB			:= ./libft/libft.a
HEADERS		:= -I ./mandatory/push_swap.h -I ./libft

all: libft/libft.a $(BIN) $(NAME)

libft/libft.a:
	@make -sC ./libft 

$(BIN)%.o: ./src/mandatory/%.c
	@$(CC) $(FLAGS) -o $@ -c $< $(HEADERS) && printf "Compiling: $(notdir $<)\n"

$(NAME): $(OBJS)
	@$(CC) $(OBJS) $(LIB) $(HEADERS) -o $(NAME)

$(BIN):
	@mkdir -p $(BIN)

tests:
	$(CC) $(CFLAGS) /.tests/test.c && ./a.out

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
	rm -rf $(BIN)
	@make clean -sC ./libft 

fclean: clean
	rm -rf $(NAME) 
	rm -rf ./libft/libft.a

re: fclean all

.PHONY: all clean fclean re