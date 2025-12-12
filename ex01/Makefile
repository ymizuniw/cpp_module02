NAME = test01
SRCS = Fixed.cpp \
	main.cpp
INCS = -I.
OBJS=$(SRCS:%.cpp=%.o)

CPP = c++
CFLAGS = -std=c++98 -Wall -Wextra -Werror

$(NAME): $(OBJS)
	$(CPP) $(CFLAGS) -o $@ $(OBJS)
%.o: %.cpp
	$(CPP) $(CFLAGS) $(INCS) -c $< -o $@

all: $(NAME)
clean:
	rm -f $(OBJS)
fclean: clean
	rm -f $(NAME)
re: fclean all

.PHONY: all clean fclean re