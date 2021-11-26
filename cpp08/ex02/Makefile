NAME = exe
CXX = clang++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98
INCLUDE = ./

SRC =	./main.cpp \
			./MutantStack.cpp

OBJ = $(SRC:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJ) MutantStack.hpp
	$(CXX) $(CXXFLAGS) -I $(INCLUDE) $(OBJ) -o $@

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJ)

fclean:
	$(RM) $(OBJ)
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
