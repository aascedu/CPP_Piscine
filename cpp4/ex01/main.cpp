#include "header.h"

int main( void )
{
	Dog test;
	{
		Dog crash = test;
	}
	
	test.callHey();
	std::cout << "hey----" << std::endl;
	test.showIdeas();

	Dog	test1;
	
	test1.callHo();
	std::cout << "ho----" << std::endl;
	test1.showIdeas();
	test1 = test;

	std::cout << "hey----" << std::endl;
	test1.showIdeas();
	test.callHo();
	std::cout << "ho----" << std::endl;
	test.showIdeas();
	std::cout << "hey----" << std::endl;
	test1.showIdeas();

	Cat chat;
	
	chat.callHey();
	std::cout << "hey----" << std::endl;
	chat.showIdeas();

	Cat	chat1;
	
	chat1.callHo();
	std::cout << "ho----" << std::endl;
	chat1.showIdeas();
	chat1 = chat;

	std::cout << "hey----" << std::endl;
	chat1.showIdeas();
	chat.callHo();
	std::cout << "ho----" << std::endl;
	chat.showIdeas();
	std::cout << "hey----" << std::endl;
	chat1.showIdeas();

	return 0;
}