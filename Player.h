//Player header file

#ifndef PLAYER_H
#define PLAYER_H

#include <string>

class Player
	{
	public:
		//Constructor
		Player();

		//Functions
		void loadFile(std::string);
		bool isDead();
		std::string getName();
		std::string getClassName();
		void setName(std::string pName);
		void createPlayer();
		int getArmour();
		void takeDamage(int damage);

	private:
		void printStars();
		void blankLine();
		std::string Name;
		std::string ClassName;
		int Accuracy;
		int HitPoints;
		int MaxHitPoints;
		int ExpPoints;
		int NextLevelExp;
		int Level;
		int Armour;
		//Weapon cWeapon;
	};

#endif //End PLAYER_H
