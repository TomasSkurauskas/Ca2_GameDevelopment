#include "Text_Stream.h"
#include<Windows.h>

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

void loadFile_DelayLine(std::string file)
	{
	std::ifstream input(file);
	std::string line;
	while (getline(input, line)) 
		{
		std::cout << line << '\n';
		Sleep(1000);
		}
	input.close();
	}