.PHONY: all clean fclean re

NAME	=	account

SRCS	=	Account.cpp														\
			tests.cpp

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

git: fclean
	git add .
	git commit -m "$m"
	git push
