#include <iostream>

int	main(int argc, char **argv)
{
	int	j;

	for (int i = 1; i < argc; i++)
	{
		j = -1;
		while (argv[i][++j])
			std::cout << (char)toupper(argv[i][j]);
		std::cout << std::endl;
	}
}