NAME = megaphone

CFLAGS = -Wall -Wextra -Werror

SRC = ./megaphone.cpp

all: $(NAME)

$(NAME): $(SRC)
	clang++ -g -std=c++98 $(CFLAGS) $^ -o $@

fclean:
	$(RM) ./megaphone

re: fclean all

.PHONY: all fclean re
