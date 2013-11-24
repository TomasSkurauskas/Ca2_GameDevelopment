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


// deal with console
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

//navigation
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
void createRooms(vector<Room> room)
	{
	for (unsigned i = 0; i < 100; i++)
		{
		Room a;
		a.setmPositon(i);
		a.setmEasth(true);
		a.setmNorth(true);
		a.setmSouth(true);
		a.setmWest(true);

		room.push_back(a);
		}
	}

//main
int main()
	{
		remove_scrollbar_set_size();

		vector<Room> room;
		
		createRooms(room);
	

	unsigned i = 0;
	while ( i <100)
		{
		string fileName = "Map/" + std::to_string(room.at(i).getmPositon()) + ".txt";
		loadFile(fileName);

		i = getDirection(i);
	//	Sleep(1000);
		}
	return 0;
	}


