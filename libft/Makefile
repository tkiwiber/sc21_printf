NAME		:=	libft.a
HDRS		:=	libft.h

# preprocessor flags
CPPFLAGS	:=	-I

# compiler flags
CFLAGS		:=	-Wall -Wextra -Werror

# compiler
CC			:=	gcc -c

#	sources for mandatory part
SRC_PART	:= 	ft_memset.c			\
				ft_bzero.c			\
				ft_memcpy.c			\
				ft_memccpy.c		\
				ft_memchr.c			\
				ft_memmove.c		\
				ft_memcmp.c			\
				ft_strlen.c			\
				ft_strlcpy.c		\
				ft_strlcat.c		\
				ft_strchr.c			\
				ft_strrchr.c		\
				ft_strnstr.c		\
				ft_strncmp.c		\
				ft_atoi.c			\
				ft_isalpha.c		\
				ft_isdigit.c		\
				ft_isalnum.c		\
				ft_isascii.c		\
				ft_isprint.c		\
				ft_toupper.c		\
				ft_tolower.c		\
				ft_calloc.c			\
				ft_strdup.c			\
				ft_substr.c			\
				ft_strjoin.c		\
				ft_strtrim.c		\
				ft_split.c			\
				ft_itoa.c			\
				ft_itoa_x.c			\
				ft_ltoa.c			\
				ft_ltoa_x.c			\
				ft_strmapi.c		\
				ft_putchar_fd.c		\
				ft_putstr_fd.c		\
				ft_putendl_fd.c		\
				ft_putnbr_fd.c		\
				ft_lstnew.c			\
				ft_lstadd_front.c	\
				ft_lstsize.c		\
				ft_lstlast.c		\
				ft_lstadd_back.c	\
				ft_lstdelone.c		\
				ft_lstclear.c		\
				ft_lstiter.c		\
				ft_lstmap.c			\
				ft_lstdisplay_bonus.c

#	object files
OBJ_PART	:=	$(SRC_PART:.c=.o)
OBJ_BONUS	:=	$(OBJ_PART) $(SRC_BONUS:.c=.o)

.PHONY: all clean fclean re bonus

all: $(NAME)

$(NAME): $(OBJ_PART) $(HDRS)
	@$(CC) $(SRC_PART) $(FLAGS)
	@ar r $(NAME) $(OBJ_PART)
	@ranlib $(NAME)
	@echo "\033[90m[\033[32mSuccess\033[90m]\033[32m Libft.a\033[0m"

/%.o: /%.c
	$(CC) $(CPPFLAGS) $(CFLAGS) -c $< -o $@

bonus: $(OBJ_BONUS) $(HDRS)
	@$(CC) $(SRC_PART) $(SRC_BONUS) $(FLAGS)
	@ar r $(NAME) $(OBJ_BONUS)
	@ranlib $(NAME)
	@echo "\033[90m[\033[32mSuccess\033[90m]\033[32m Libft.a + Bonus\033[0m"

clean:
	@rm -f *.o
	@echo "\033[90m[\033[91mDeleting\033[90m]\033[31m Done\033[0m"

fclean: clean
	@/bin/rm -f $(NAME)
	@echo "\033[90m[\033[91mRemoving\033[90m]\033[31m Done\033[0m"

re: fclean all