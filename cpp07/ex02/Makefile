NAME = exe
CFLAGS = -Wall -Wextra -Werror -std=c++98
INCLUDE = ./

SRC =	./main.cpp


OBJ = $(SRC:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJ) Array.hpp
	clang++ -g $(CFLAGS) -I $(INCLUDE) $< -o $@

%.o: %.cpp
	clang++ -g $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJ)

fclean:
	$(RM) $(OBJ)
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
