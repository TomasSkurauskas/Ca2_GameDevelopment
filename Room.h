// Room.h

#ifndef ROOM_H
#define ROOM_H
#include<string>

class Room
	{
	public:
		//construtcor
		Room();
		Room(int position);
		Room(std::string name, bool north, bool south, bool easth, bool west, int position);

		//setters
		void setmName(std::string);
		void setmPositon(int);
		void setmNorth(bool);
		void setmSouth(bool);
		void setmEasth(bool);
		void setmWest(bool);

		//getters
		std::string getmName();
		bool getmNorth();
		bool getmSouth();
		bool getmEasth();
		bool getmWest();
		int getmPositon();

	private:
		//variables
		std::string mName;
		bool mNorth;
		bool mSouth;
		bool mEasth;
		bool mWest;
		int mPosition;
	};
#endif // Room_H