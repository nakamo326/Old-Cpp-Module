NAME = megaphone

CFLAGS = -Wall -Wextra -Werror

SRC = ./megaphone.cpp

all: $(NAME)

$(NAME): $(SRC)
	clang++ -g -std=c++03 $(CFLAGS) $^ -o $@

clean:
	$(RM) ./megaphone

re: clean all

.PHONY: all clean re
