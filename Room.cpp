// Wiz.cpp

#include "Room.h"
#include <iostream>


Room::Room()
	{
	mName = "Default";
	mNorth = false;
	mSouth = false;
	mEasth = false;
	mWest = false;
	mPosition = 0;
	}
Room::Room(int position)
	{
	mName = "Default";
	mNorth = false;
	mSouth = false;
	mEasth = false;
	mWest = false;
	mPosition = position;
	}

Room::Room(std::string name, bool north, bool south, bool easth, bool west, int position)
	{
	mName = name;
	mNorth = north;
	mSouth = south;
	mEasth = easth;
	mWest = west;
	mPosition = position;
	}
//setters
void Room::setmName(std::string name)
	{
	mName = name;
	}
void Room::setmNorth(bool north)
	{
	mNorth = north;
	}
void Room::setmSouth(bool south)
	{
	mSouth = south;
	}
void Room::setmEasth(bool easth)
	{
	mEasth = easth;
	}
void Room::setmWest(bool west)
	{
	mWest = west;
	}
void Room::setmPositon(int position)
	{
	mPosition = position;
	}


//getters
std::string Room::getmName()
	{
	return mName;
	}
bool Room::getmNorth()
	{
	return mNorth;
	}
bool Room::getmSouth()
	{
	return mSouth;
	}
bool Room::getmEasth()
	{
	return mEasth;
	}
bool Room::getmWest()
	{
	return mWest;
	}
int Room::getmPositon()
	{
	return mPosition;
	}