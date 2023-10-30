SRCS = 	main.cpp \
		Harl.cpp

HEADER = Harl.hpp

OBJS = $(SRCS:.cpp=.o)

CPP = c++
RM = @rm -rf
CPPFLAGS = -Wall -Werror -Wextra -I./include/ -std=c++98

NAME = Harl

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

re: fclean
	make all

.PHONY: all clean fclean re