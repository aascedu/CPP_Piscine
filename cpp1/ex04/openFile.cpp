#include "openFile.hpp"

std::fstream	getFileInfo(char *filename)
{
	std::fstream	fs;

	fs.open(filename, std::fstream::in);
	return fs;
}