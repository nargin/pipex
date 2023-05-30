SRC = ./srcs/main.c ./srcs/utils.c
	
OBJS = $(SRC:.c=.o)
RM = rm -f
NAME = pipex
LIB = ./includes/libft/libft.a
CC = gcc
CFLAGS = -Wall -Wextra -Werror -g


all : author ${LIB} $(NAME)

${LIB} :
	@make -s -C ./includes/libft/ all
	@echo Libft is ready.

author :
	@echo "Author :\tcparras"
	@echo "Project :\t$(NAME)"
	@echo --------------------------------------------------------

PRINT_NAME = 1

%.o: %.c
	@if [ $(PRINT_NAME) -eq 1 ]; then echo -n "$(NAME) : "; fi
	@$(CC) $(FLAGS) -c $< -o $@
	@echo -n "\033[32m✔\033[0m"
	@$(eval PRINT_NAME = 0)

$(NAME) : $(OBJS) ${LIB}
	@${CC} ${CFLAGS} $(OBJS) -L./includes/libft -lft -o $(NAME)
	@echo
	@echo $(NAME) is runable.

clean :
	@${RM} ${OBJS}
	@make -s -C ./includes/libft/ clean
	@echo Object files removed.

fclean : clean
	@${RM} $(NAME)
	@make -s -C ./includes/libft/ fclean
	@echo ${NAME} removed.

re : author fclean all
		@echo Rebuild done.

.PHONY: all clean fclean re
