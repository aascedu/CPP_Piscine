SRCS = 	main.cpp \
		Data.cpp

HEADER = Data.hpp

OBJS = $(SRCS:.cpp=.o)

CPP = c++
RM = @rm -rf
CPPFLAGS = -Wall -Werror -Wextra -I. -std=c++98

NAME = Serial

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