SRCS = 	main.cpp \
		PhoneBook.cpp \
		Contact.cpp \

HEADER = PhoneBook.hpp Contact.hpp

OBJS = $(SRCS:.cpp=.o)

CPP = c++
RM = @rm -rf
CPPFLAGS = -Wall -Werror -Wextra -I./include/ -std=c++98

NAME = PhoneBook

all:
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