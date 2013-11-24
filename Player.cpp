#include "Player.h"
#include <iostream>
#include <fstream>



//using namespace std;
Player::Player()
	{
	Name = "Default";
	ClassName = "Default";
	Accuracy = 0;
	HitPoints = 0;
	MaxHitPoints = 0;
	ExpPoints = 0;
	NextLevelExp = 0;
	Level = 0;
	Armour = 0;
	}

std::string Player::getName()
	{
	return Name;
	}

void Player::setName(std::string pName)
	{
	this->Name = pName;
	}

void Player::createPlayer()
	{	

	//Input the character's name
	std::cout << "\t\t\t\t\t\t\tEnter your name: ";
	std::cin >> Name;
	//Select a charactor to play as
	std::cout <<"\t\t\t\t\t\t\t"<< Name << " please select a character to play as" << std::endl;

	std::cout << "\t\t\t\t\t\t\t1)Human" << std::endl;
	std::cout << "\t\t\t\t\t\t\t2)Anka" << std::endl;
	std::cout << "\t\t\t\t\t\t\t3)Centaur" << std::endl;
	std::cout << "\t\t\t\t\t\t\t4)Ekimmu " << std::endl;
	

	int charNumber = 1;
	std::cin >> charNumber;
	std::cin.ignore();

	switch (charNumber)
		{
		case 1:
			//Human
			ClassName = "Human";
			Accuracy = 12;
			HitPoints = 7;
			MaxHitPoints = 15;
			ExpPoints = 0;
			NextLevelExp = 1000;
			Level = 1;
			Armour = 0;
			std::cout << "Humans are accurate with there blows "
				<< "\nand cause an average amout of damage"
				<< "\nwith a stike but do not have any body armour"
				<< std::endl;
			break;

		case 2:
			//Anka
			ClassName = "Anka";
			Accuracy = 16;
			HitPoints = 3;
			MaxHitPoints = 9;
			ExpPoints = 0;
			NextLevelExp = 1000;
			Level = 1;
			Armour = 3;
			std::cout << "Anka's are very accurate with there blows"
				<< "\nand cause a minimal amout of damage"
				<< "\nwith a stike but do not have much body Armour"
				<< std::endl;
			break;
		case 3:
			//Centaur
			ClassName = "Centaur";
			Accuracy = 3;
			HitPoints = 8;
			MaxHitPoints = 20;
			ExpPoints = 0;
			NextLevelExp = 1000;
			Level = 1;
			Armour = 7;
			std::cout << "Centaur's are not very accurate with there blows"
				<< "\nbut cause a average amount of damage"
				<< "\nwith a stike and have lots of body Armour"
				<< std::endl;
			break;

		case 4:
			//Ekimmu
			ClassName = "Ekimmu";
			Accuracy = 6;
			HitPoints = 6;
			MaxHitPoints = 10;
			ExpPoints = 0;
			NextLevelExp = 1000;
			Level = 1;
			Armour = 7;
			std::cout << "Ekimmu's have an average amount of stenth with there blows"
				<< "\nand cause an average amount of damage"
				<< "\nwith a stike and have an average amount of body Armour"
				<< std::endl;
			break;
		}
	}


std::string Player::getClassName()
	{
	return this->ClassName;
	}

bool Player::isDead()
	{
	return HitPoints <= 0;
	}

void Player::takeDamage(int damage)
	{
	HitPoints -= damage;
	}

int Player::getArmour()
	{
	return Armour;
	}

