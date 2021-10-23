NAME = ex06
CFLAGS = -Wall -Wextra -Werror
INCLUDE = ./

SRC =	./main.cpp \
		./Weapon.cpp \
		./HumanA.cpp \
		./HumanB.cpp

OBJ = $(SRC:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJ)
	clang++ -g -std=c++98 $(CFLAGS) -I $(INCLUDE) $^ -o $@

%.o: %.cpp
	clang++ -g -std=c++98 $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(NAME)

fclean:
	$(RM) $(OBJ)
	$(RM) $(NAME)

re: clean all

.PHONY: all clean re
