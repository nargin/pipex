NAME = libft.a
CC = gcc
SRCS = 	ft_isalpha.c \
       	ft_isdigit.c \
       	ft_isalnum.c \
       	ft_isascii.c \
       	ft_isprint.c \
       	ft_strlen.c \
       	ft_memset.c \
       	ft_bzero.c \
       	ft_memcpy.c \
       	ft_memmove.c \
       	ft_strlcpy.c \
       	ft_strlcat.c \
       	ft_toupper.c \
       	ft_tolower.c \
       	ft_strchr.c \
       	ft_strrchr.c \
       	ft_strncmp.c \
       	ft_memchr.c \
       	ft_memcmp.c \
       	ft_strnstr.c \
       	ft_atoi.c \
       	ft_calloc.c \
       	ft_strdup.c \
       	ft_substr.c \
		ft_strtrim.c \
        ft_split.c \
	  	ft_itoa.c \
	  	ft_strmapi.c \
	  	ft_striteri.c \
	  	ft_putchar_fd.c \
	  	ft_putstr_fd.c \
	  	ft_putendl_fd.c \
	  	ft_putnbr_fd.c \
		ft_strjoin.c \
		ft_strlen.c \
		get_next_line_bonus.c \
		get_next_line_utils_bonus.c \
		ft_printf.c \
		ft_printf_utils.c \
		ft_lstnew.c \
		ft_lstdelone.c \
		ft_lstclear.c \
		ft_lstadd_front.c \
		ft_lstsize.c \
		ft_lstlast.c \
		ft_lstadd_back.c \
		printerr.c	\
		fresh_str.c \
		ft_arraylen.c \
		free_array.c

OBJS = $(SRCS:.c=.o)

FLAGS = -Wall -Wextra -Werror

RM = rm -f

$(NAME) : $(OBJS)
	@ar rc $(NAME) $(OBJS)
	@echo 
	@rm -f $(OBJS)

PRINT_LIBFT = 1

%.o: %.c
	@if [ $(PRINT_LIBFT) -eq 1 ]; then echo -n "Libft : "; fi
	@$(CC) $(FLAGS) -c $< -o $@
	@echo -n "\033[32m✔\033[0m"
	@$(eval PRINT_LIBFT = 0)


all : $(NAME) 

clean :
	$(RM) $(OBJS)

fclean : clean
	$(RM) $(NAME)

re : fclean all
