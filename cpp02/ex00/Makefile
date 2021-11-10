NAME = ex00
CFLAGS = -Wall -Wextra -Werror
INCLUDE = ./

SRC =	./main.cpp \
			./Fixed.cpp

OBJ = $(SRC:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CXX) -g -std=c++98 $(CFLAGS) -I $(INCLUDE) $^ -o $@

%.o: %.cpp
	$(CXX) -g -std=c++98 $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(NAME)

fclean:
	$(RM) $(OBJ)
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
