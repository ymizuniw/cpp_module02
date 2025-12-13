#default make all
NAME_0=test020
NAME_1=test021
NAME_2=test022
TESTS=$(NAME_0) $(NAME_1) $(NAME_2)
all : $(TESTS)

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

#test020 builder
MAIN_0=main0.cpp
SRCS_0=$(SRCS) $(MAIN_0)
OBJS_0=$(SRCS_0:%.cpp=%.o)
$(NAME_0) : $(OBJS_0)
	$(CXX) $(CXXFLAGS) -o $@ $(OBJS_0)
#test021 builder
MAIN_1=main1.cpp
SRCS_1=$(SRCS) $(MAIN_1)
OBJS_1=$(SRCS_1:%.cpp=%.o)
$(NAME_1): $(OBJS_1)
	$(CXX) $(CXXFLAGS) -o $@ $(OBJS_1)

#test022 builder
MAIN_2=main2.cpp
SRCS_2=$(SRCS) $(MAIN_2)
OBJS_2=$(SRCS_2:%.cpp=%.o)
$(NAME_2): $(OBJS_2)
	$(CXX) $(CXXFLAGS) -o $@ $(OBJS_2)

clean:
	$(RM) -f $(OBJS_0)
	$(RM) -f $(OBJS_1)
	$(RM) -f $(OBJS_2)
fclean: clean
	rm -f $(TESTS)
re: fclean all
.PHONY : all clean fclean re
