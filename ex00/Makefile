NAME = test00
SRCS = Fixed.cpp \
main.cpp
INCS = -I.
OBJS=$(SRCS:%.cpp=%.o)

CXX = c++
CXXFLAGS = -std=c++98 -Wall -Wextra -Werror

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $(OBJS)
%.o: %.cpp
	$(CXX)	$(CXXFLAGS)	-c $< -o $@

all: $(NAME)
clean:
	rm -f $(OBJS)
fclean: clean
	rm -f $(NAME)
re: fclean all
.PHONY:	all clean fclean re