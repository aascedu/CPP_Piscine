SRCS = 	main.cpp \
		AMateria.cpp \
		Cure.cpp \
		Ice.cpp \
		Character.cpp \
		MateriaSource.cpp

HEADER = AMateria.hpp Cure.hpp Ice.hpp ICharacter.hpp Character.hpp IMateriaSource.hpp MateriaSource.hpp

OBJS = $(SRCS:.cpp=.o)

CPP = c++
RM = @rm -rf
CPPFLAGS = -Wall -Werror -Wextra -std=c++98 -g3 -fsanitize=address

NAME = Interface

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