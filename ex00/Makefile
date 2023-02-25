.PHONY: all clean fclean re

NAME	= megaphone

SRCS	= megaphone.cpp
OBJS	= $(SRCS:.cpp=.o)

CXX	:= c++
CXXFLAGS := -Wall -Werror -Wextra -std=c++98

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(OBJS) -o $@

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -o $@ -c $<

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re:	fclean all

git: clean
	git add .
	git commit -m "$m"
	git push

####	TESTS	####
test1:
	./$(NAME)

test2:
	./$(NAME) "shhhhh... I think the students are asleep..."

test3:
	./$(NAME) Damnit " ! " "Sorry students, I thought this thing was off."

