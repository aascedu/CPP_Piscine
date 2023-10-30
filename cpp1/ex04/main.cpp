#include <fstream>
#include <iostream>

int	main(int argc, char **argv)
{
	if (argc != 4)
		return (1);
	std::ifstream	is(argv[1], std::ifstream::binary);
	if (!is)
		std::cout << "Error when opening file" << std::endl;
	else
	{
		is.seekg(0, is.end);
		int	length = is.tellg();
		is.seekg(0, is.beg);
		char	*buffer = new char [length + 1];
		is.read(buffer, length);
		is.close();
		buffer[length] = '\0';
		std::string str = buffer;
		delete[] buffer;
		std::string	search = argv[2];
		std::string	add = argv[3];
		int	pos = 0;
		while (1)
		{
			if (str.find(argv[2], pos) != std::string::npos)
			{
				pos = str.find(argv[2], pos);
				str.erase(pos, search.length());
				str.insert(pos, argv[3]);
				pos += add.length();
			}
			else
				break;
		}
		std::string	filename = argv[1];
		filename.insert(filename.length(), ".replace");
		std::ofstream	outfile;
		outfile.open(filename.c_str());
		if (!outfile)
			return (1);
		outfile << str;
		outfile.close();
	}
	return (0);
}