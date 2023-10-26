SRCS = 	tests.cpp \
		Account.cpp

HEADER = Account.hpp

OBJS = $(SRCS:.cpp=.o)

CPP = c++
RM = @rm -rf
CPPFLAGS = -Wall -Werror -Wextra -I./include/ -std=c++98

NAME = 

all: $(OBJS_DIR)
	@make $(NAME)

%.o : %.cpp
	$(CPP) $(CPPFLAGS) -o $@ -c $<

$(NAME): $(OBJS) $(HEADER)
	$(CPP) $(CPPFLAGS) $(OBJS) -o $(NAME)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean
	@make all

.PHONY: all clean fclean re