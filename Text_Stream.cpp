#include "Text_Stream.h"

void loadFile(std::string file)
	{
	std::ifstream input(file);
	std::string line;
	while (getline(input, line))
		{
		std::cout << line << '\n';
		}
	input.close();
	}