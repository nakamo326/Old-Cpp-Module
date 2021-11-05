NAME = ex02

CFLAGS = -Wall -Wextra -Werror

SRC = ./test.cpp \
			./Account.cpp

all: $(NAME)

$(NAME): $(SRC)
	clang++ -g -std=c++98 $(CFLAGS) $^ -o $@

test: all
	diff 19920104_091532.log `./ex02`

clean:
	$(RM) ./megaphone

re: fclean all

.PHONY: all clean re
