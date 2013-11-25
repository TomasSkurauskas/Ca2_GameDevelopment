// main.cpp
#include "Room.h"
#include "Text_Stream.h"
#include "Player.h"
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


int getDirection(int currentPlace, Room temp)
	{
	unsigned choise = 0;

	do 
		{		
	cout << "|\t\t\t\t1:north , 2: South, 3: West, 4: East" << endl;
	cin >> choise;
		} while (choise < 1 || choise > 4);


	if (choise == 1)
		{
		if (temp.getmNorth() == true)
			{
			return currentPlace - 10;
			}
		else
			{
			std::cout << "|\t\t\t\tYour can't travel north!!!!!!" << std::endl;
			std::cin;
			return currentPlace;
			}
		}
	else if (choise == 2)
		{
		if (temp.getmSouth() == true)
			{
			return currentPlace + 10;
			}
		else
			{
			std::cout << "|\t\t\t\tYour can't travel south!!!!!!" << std::endl;
			std::cin;
			return currentPlace;
			}
		}
	else if (choise == 3)
		{
		if (temp.getmWest() == true)
			{
			return currentPlace - 1;
			}
		else
			{
			std::cout << "|\t\t\t\tYour can't travel westh!!!!!!" << std::endl;
			std::cin;
			return currentPlace;
			}
		}
	else if (choise == 4)
		{
		if (temp.getmEasth() == true)
			{
			return currentPlace + 1;
			}
		else
			{
			std::cout << "|\t\t\t\tYour can't travel East!!!!!!" << std::endl;
			std::cin;
			return currentPlace;
			}
		}
	}


	
void size(int arr1[])
	{
	int size;
	size = sizeof(arr1) / sizeof(arr1[0]);
	cout << size << endl;
	}

int main()
	{
	remove_scrollbar_set_size();
	vector<Room> room;

	Room tempRoom;
	Player mainPlayer;
	 
	int north[] = { 0,1, 2, 3, 4, 5, 6, 7, 8, 9,12,30,31,32,39,60,61,65,66,80,81,88,89};
	 int south[] = {10,11,12,17,19,48,49,50,51,55,56,70,71,73,74,75,76,90, 91, 92, 93, 94, 95, 96, 97, 98, 99 };
	 int westh[] = { 0,3, 10,20,23, 27,30,37,38, 40, 47,48,50,57, 60,67,70,77,72,73,75, 80, 90 ,98};
	 int east[] = { 1,9, 19,26, 29, 36,39, 46,49,56, 59,66, 69, 71,74,76,79, 82,89,92,97, 99 };

	for (unsigned i = 0; i < 100; i++)
		{
		tempRoom.setmPositon(i);
		tempRoom.setmNorth(true);
		tempRoom.setmSouth(true);
		tempRoom.setmWest(true);
		tempRoom.setmEasth(true);
		
		for (unsigned b = 0; b <(sizeof(north) / sizeof(north[0])); b++)
			{
			if (north[b] == i)
				{
				tempRoom.setmNorth(false);
				}			
			}
		for (unsigned b = 0; b <(sizeof(south) / sizeof(south[0])); b++)
			{
			if (south[b] == i)
				{
				tempRoom.setmSouth(false);
				}
			}
		for (unsigned b = 0; b <(sizeof(westh) / sizeof(westh[0])); b++)
			{
			if (westh[b] == i)
				{
				tempRoom.setmWest(false);
				}
			}
		for (unsigned b = 0; b <(sizeof(east) / sizeof(east[0])); b++)
			{
			if (east[b] == i)
				{
				tempRoom.setmEasth(false);
				}
			}
		room.push_back(tempRoom);
		}

	loadFile_DelayLine("Map/Intro.txt");
	mainPlayer.createPlayer();
	Sleep(2000);

	unsigned i = 0;
	while (i < 100)
		{
		string fileName = "Map/" + std::to_string(room.at(i).getmPositon()) + ".txt";
		loadFile(fileName);

		Room temp = room.at(i);
		i = getDirection(i, temp);
		}
	return 0;
	}


