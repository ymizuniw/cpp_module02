#common srcs
SRCS=Fixed.cpp\
	int_part_range_check.cpp
#common compiler options
CXX=c++
CXXFLAGS=-std=c++98 -Wall -Wextra -Werror
CPPFLAGS=-I.
#common pattern rules
%.o : %.cpp
	$(CXX) $(CXXFLAGS) $(CPPFLAGS) -c $< -o $@

#test021 builder
TEST1=test021
MAIN1=main1.cpp
TEST1_SRCS=$(SRCS) $(MAIN1)
TEST1_OBJS=$(TEST1_SRCS:%.cpp=%.o)
test01: $(TEST1)
$(TEST1): $(TEST1_OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $(TEST1_OBJS)

#test022 builder
TEST2=test022
MAIN2=main2.cpp
TEST2_SRCS=$(SRCS) $(MAIN2)
TEST2_OBJS=$(TEST2_SRCS:%.cpp=%.o)
test02: $(TEST2)
$(TEST2): $(TEST2_OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $(TEST2_OBJS)

#default target builder
#default target
NAME=test020
MAIN0=main0.cpp
DEFAULT_SRCS=$(SRCS) $(MAIN0)
DEFAULT_OBJS=$(DEFAULT_SRCS:%.cpp=%.o)
$(NAME) : $(DEFAULT_OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $(DEFAULT_OBJS)

all : $(NAME)
clean:
	$(RM) -f $(OBJS)
	$(RM) -f $(TEST1_OBJS)
	$(RM) -f $(TEST2_OBJS)
	find . -maxdepth 1 -type f -name 'main[0-9].o' -delete
fclean: clean
	rm -f test[0-9][0-9][0-9]
re: fclean all
.PHONY : all clean fclean re
