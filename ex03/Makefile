NAME=test00
SRCS=bsp.cpp\
Fixed.cpp\
int_part_range_check.cpp\
Point.cpp\
main.cpp
CPPFLAGS=-I.
OBJS=$(SRCS:%.cpp=%.o)
CXX=c++
CXXFLAGS=-std=c++98 -Wall -Wextra -Werror

all : $(NAME)
clean:
	$(RM) $(OBJS)
fclean: clean
	$(RM) $(NAME)
re: fclean all
.PHONY: all clean fclean re

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $(OBJS)
%.o : %.cpp
	$(CXX) $(CXXFLAGS) -c $< $(CPPFLAGS) -o $@