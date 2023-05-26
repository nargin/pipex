SRC = pipex.c

OBJS = $(SRC:.c=.o)

RM = rm -f

NAME = pipex

all : $(NAME)

bonus : $(NAME)

$(NAME) :	$(OBJS)
				gcc -Wall -Werror -Wextra $(OBJS) -I ./ -o $(NAME)

.c.o:
		gcc -Wall -Werror -Wextra -I ./ -c $< -o $(<:.c=.o)
	
clean :
		$(RM) $(OBJS)

fclean :	clean
				$(RM) $(NAME)

re:	fclean all

.PHONY: all clean fclean re