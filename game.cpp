// main.cpp
#include "Room.h"
#include "Text_Stream.h"
#include <iostream>
#include <fstream>
#include<string>
#include<vector>
#include<Windows.h>

using std::cout;
using std::endl;
using std::cin;
using std::string;
using std::vector;



void remove_scrollbar_set_size()
	{
	HWND console = GetConsoleWindow();
	RECT r;
	GetWindowRect(console, &r); //stores the console's current dimensions
	//MoveWindow(window_handle, x, y, width, height, redraw_window);
	MoveWindow(console, r.left, r.top, 760, 600, TRUE);

	CONSOLE_SCREEN_BUFFER_INFO info;
	GetConsoleScreenBufferInfo(console, &info);
	COORD new_size =
		{
		info.srWindow.Right - info.srWindow.Left + 1,
		info.srWindow.Bottom - info.srWindow.Top + 1
		};	
	SetConsoleScreenBufferSize(console, new_size);
	}


int getDirection(int currentPlace)
	{

	cout << "1:north , 2: South, 3: West, 4: East" << endl;
	int choise;
	cin >> choise;

	if (choise == 1)
		{
		return currentPlace - 10;
		}
	else if (choise == 2)
		{
		return currentPlace + 10;
		}
	else if (choise == 3)
		{
		return currentPlace - 1;
		}
	else if (choise == 4)
		{
		return currentPlace + 1;
		}
	}


int main()
	{
		remove_scrollbar_set_size();
		vector<Room> room;
	
		Room a;
	for (unsigned i = 0; i < 100; i++)
		{		
		a.setmPositon(i);
		room.push_back(a);
		}

	unsigned i = 0;
	while ( i <100)
		{
		string fileName = "Map/" + std::to_string(room.at(i).getmPositon()) + ".txt";
		loadFile(fileName);

		i = getDirection(i);
		Sleep(1000);
		}
		

	return 0;
	}


