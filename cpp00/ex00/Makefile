NAME = megaphone

CFLAGS = -Wall -Wextra -Werror

SRC = ./megaphone.cpp

all: $(NAME)

$(NAME): $(SRC)
	clang++ -g -std=c++98 $(CFLAGS) $^ -o $@

clean:
	$(RM) ./megaphone

re: fclean all

.PHONY: all clean re
