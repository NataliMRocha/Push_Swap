NAME		:= push_swap
CC			:= gcc
FLAGS		:= -Wall -Wextra -Werror -g3
BIN			:= ./bin/
SRCS		:= $(addprefix ./src/mandatory/, push_swap.c linked_list.c error.c check_and_allocate_args.c)
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

clean:
	rm -rf $(BIN)
	@make clean -sC ./libft 

fclean: clean
	rm -rf $(NAME) 
	rm -rf ./libft/libft.a

re: fclean all

.PHONY: all clean fclean re