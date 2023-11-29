SRCS = 	main.cpp \
		ScalarConverter.cpp

HEADER = ScalarConverter.hpp

OBJS = $(SRCS:.cpp=.o)

CPP = c++
RM = @rm -rf
CPPFLAGS = -Wall -Werror -Wextra -I. -MMD -MP -std=c++98

DEPS = $(SRCS:.cpp=.d)

-include $(DEPS)

NAME = Convert

all:
	make $(NAME)

$(NAME): $(OBJS) 
	$(CPP) $(CPPFLAGS) $(OBJS) -o $(NAME)

%.o : %.cpp $(HEADER)
	$(CPP) $(CPPFLAGS) -o $@ -c $<

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)
	$(RM) $(DEPS)

re: fclean
	make all

.PHONY: all clean fclean re