NAME = ex02
CFLAGS = -Wall -Wextra -Werror
INCLUDE = ./

SRC =	./main.cpp \
		./Zombie.cpp \
		./ZombieEvent.cpp

OBJ = $(SRC:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJ)
	clang++ -g -std=c++03 $(CFLAGS) -I $(INCLUDE) $^ -o $@

%.o: %.cpp
	clang++ -g -std=c++03 $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(NAME)

fclean:
	$(RM) $(OBJ)
	$(RM) $(NAME)

re: clean all

.PHONY: all clean re
