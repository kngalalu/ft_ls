# Name of the final executable
NAME = ft_ls

# Paths
SRCS_PATH = srcs/
OBJ_PATH  = obj/
LIBFT_PATH = libft/

# Compiler flags
FLAGS = -Wall -Werror -Wextra
INC = -I ./includes/ -I ./$(LIBFT_PATH)includes/

# Source files
SRCS_NAME = main.c \
            parsing.c \
            add_new_file.c \
            sort_list.c \
            display_all.c \
            display_list.c \
            display_detailed_list.c \
            display_list_items.c \
            misc.c

# Object files
SRCS = $(addprefix $(SRCS_PATH), $(SRCS_NAME))
OBJ = $(addprefix $(OBJ_PATH), $(SRCS_NAME:.c=.o))

# Default target
all: $(NAME)

# Link object files and create the executable
$(NAME): $(OBJ)
	@make -C $(LIBFT_PATH)
	@gcc $(FLAGS) $(OBJ) $(INC) -L $(LIBFT_PATH) -lft -o $(NAME)
	@echo "\033[32mBinary \033[1;32m$(NAME)\033[1;0m\033[32m created.\033[0m"

# Compile source files into object files
$(OBJ_PATH)%.o: $(SRCS_PATH)%.c
	@mkdir -p $(OBJ_PATH)
	@gcc -c $(FLAGS) $(INC) $< -o $@
	@echo "\033[34m\033[1mCompilation of \033[0m\033[36m$(notdir $<)\033[1m\033[34m done.\033[0m"

# Clean object files
clean:
	@make -C $(LIBFT_PATH) clean
	@rm -rf $(OBJ_PATH)
	@echo "\033[31mObject files removed.\033[0m"

# Clean object files and the executable
fclean: clean
	@make -C $(LIBFT_PATH) fclean
	@rm -rf $(NAME)
	@echo "\033[31mBinary \033[1;31m$(NAME)\033[1;0m\033[31m removed.\033[0m"

# Rebuild the project
re: fclean all

# Phony targets
.PHONY: all clean fclean re