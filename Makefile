NAME 					:=	libftprintf.a

CC						:=	gcc
LIBFT_DIR 				:=	libft/
SRC_DIR 				:=	src/
OBJ_DIR 				:=	obj/
OBJ_LIBFT_DIR 			:=	libft/

SRC_FILES				:=	ft_printf.c			\
							ft_print_d.c		\
							ft_print_d_funcs.c	\
							ft_print_u.c		\
							ft_print_u_funcs.c	\
							ft_print_x.c		\
							ft_print_o.c		\
							ft_print_p.c		\
							ft_print_c.c		\
							ft_print_s.c		\
							ft_print_pct.c		\
							ft_mask_get_funcs.c	\
							ft_placeholder.c	\

LIBFT_FILES 			:=	ft_memset.c			\
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

OBJ_FILES 					:= $(SRC_FILES:.c=.o)
OBJ_LIBFT_FILES 			:= $(LIBFT_FILES:.c=.o)

SRC 						:= $(addprefix $(SRC_DIR), $(SRC_FILES)) $(addprefix $(LIBFT_DIR), $(LIBFT_FILES))

INC 						:= -Iincludes/
CINC 						:= libft/libft.h
FLAGS 						:= -g -Wall -Werror -Wextra

ifdef WITH_BONUS
OBJ 						:= $(addprefix $(OBJ_DIR), $(OBJ_FILES)) $(addprefix $(LIBFT_DIR), $(OBJ_LIBFT_FILES))
else
OBJ 						:= $(addprefix $(OBJ_DIR), $(OBJ_FILES)) $(addprefix $(LIBFT_DIR), $(OBJ_LIBFT_FILES))
endif

.PHONY: all clean fclean re libft bonus

all: $(NAME)

$(NAME): $(OBJ)
	@ar rc $(NAME) $(OBJ)
	@ranlib $(NAME)
	@echo "\033[90m[\033[32mSuccess\033[90m]\033[32m libftprintf.a\033[0m"

bonus:
	$(MAKE) WITH_BONUS=1 all

$(OBJ_DIR)%.o: $(SRC_DIR)%.c $(CINC)
	@mkdir -p $(OBJ_DIR)
	@$(CC) $(INC) $(FLAGS) -c -g $< -o $@

$(OBJ_LIBFT_DIR)%.o: $(LIBFT_DIR)%.c libft/libft.h
	@$(MAKE) -C libft/ all #bonus

clean:
	@mkdir -p $(OBJ_DIR)
	@$(MAKE) -C libft/ clean
	@rm -f $(OBJ_DIR)/*.o
	@echo "\033[90m[\033[91mDeleting\033[90m]\033[31m Done\033[0m"

fclean: clean
	@$(MAKE) -C libft/ fclean
	@rm -f $(NAME)
	@echo "\033[90m[\033[91mRemoving\033[90m]\033[31m Done\033[0m"

re: fclean all