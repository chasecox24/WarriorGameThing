#pragma once

#include"Character.h"	

class Game
{
	bool isRunning = true;
	Character playerCharacter;

public:
	Game(); // default constructor

	//Main game functions
	void startGame();
	void gameLoop();

	//Character creation functions
	Character createPlayerCharacter();
	Weapon selectStarterWeapon();
	Armor selectStarterArmor();

	//Creation functions
	Weapon createWeapon();
	Armor createArmor();

	//Utility functions
	void waitForInput(); //its TRASH and takes the previous characters inputted
};