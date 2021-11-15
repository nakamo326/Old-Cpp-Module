NAME = ex03
CFLAGS = -Wall -Wextra -Werror
INCLUDE = ./

SRC =	./main.cpp \
			./AMateria.cpp \
			./Character.cpp \
			./Cure.cpp \
			./Ice.cpp \
			./MateriaSource.cpp

OBJ = $(SRC:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJ)
	clang++ -g -std=c++98 $(CFLAGS) -I $(INCLUDE) $^ -o $@

%.o: %.cpp
	clang++ -g -std=c++98 $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJ)

fclean:
	$(RM) $(OBJ)
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
