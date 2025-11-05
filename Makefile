NAME := libftprintf.a

CC := cc

SRC := 	ft_printf.c \
		ft_putvoid.c \
		ft_putnbr_base.c

SRC_BONUS :=	 \

CFLAGS := -Wall -Wextra -Werror

OBJ := $(SRC:.c=.o)

OBJ_BONUS := $(SRC_BONUS:.c=.o)

all : $(NAME)

bonus : $(OBJ) $(OBJ_BONUS)
	ar rcs $(NAME) $(OBJ) $(OBJ_BONUS)

$(NAME): $(OBJ)
	ar rcs $(NAME) $(OBJ)

%.o: %.c ft_printf.h ../libft/libft.h
	$(CC) $(CFLAGS) -c $< -o $@
clean :
	rm -f $(OBJ) $(OBJ_BONUS)

fclean : clean
	rm -f $(NAME)

re : fclean all

.PHONY : all bonus clean fclean re
