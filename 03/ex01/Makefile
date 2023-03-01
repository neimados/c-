SRCS = main.cpp ClapTrap.cpp ScavTrap.cpp
CC = c++
NAME = serena
HEADERS = ClapTrap.hpp ScavTrap.hpp
CFLAG = -Wall -Wextra -Werror -std=c++98
OBJS = $(SRCS:.cpp=.o)


all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAG) -o $(NAME) $(OBJS)

%.o : %.cpp $(HEADERS) Makefile
	$(CC) $(CFLAG) -I . -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re