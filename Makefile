NAME = ft_ls

SRC = action_ls.c recursion.c main.c flag_parsing.c implement.c printing_ls.c print_l.c sort.c sorting.c\
			details.c block_size.c free_memory.c permissions.c symbolic_link.c user.c argv_count.c error.c
OBJ_NAME = $(SRC:.c=.o)

all: $(NAME)

$(NAME): 
	@echo "\033[0;32m <<<<<<Compiling $(NAME)>>>>>> \033[0m"
	@make -C libft/
	@gcc $(FLAGS) -o $(NAME) $(SRC) libft/libft.a -ggdb3
	@echo "\033[0;32m <<<<<<<<<<< DONE >>>>>>>>>> \033[0m"

clean:
	/bin/rm -f $(OBJ_NAME)

fclean:
	@echo "\033[0;31m <<<<<<<<<< cleaning libft >>>>>>>>>> \033[0m"
	@make fclean -C libft/
	@/bin/rm -f $(NAME)
	@echo "\033[0;31m <<<<<<<<<< Removed exe and cleaned libft>>>>>>>>>> \033[0m"
	make -C libft fclean
	rm -f $(NAME)
	@echo "\033[0;31m <<<<<<< cleaned >>>>>> \033[0m"

re: fclean all

