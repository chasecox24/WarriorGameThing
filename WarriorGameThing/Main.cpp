// WarriorGameThing.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include<algorithm>
#include"Character.h"

using namespace std; 

int main()
{


	//using integer = int; 

	//integer a = 123; 

	Armor basicArmor("Basic Armor", 10);
	Weapon basicWeapon("Basic Weapon", 20, 1);

	Character mainCharacter("Main Character", 100, 10, basicWeapon, basicArmor);
	mainCharacter.printStats();

	Character enemy1("Enemy1", 50, 2, 12, 12);
	enemy1.printStats();

	mainCharacter.attack(enemy1);
	enemy1.attack(mainCharacter);


	//Enemy realEnemy()
	Enemy realEnemy("Real Enemy Class", 100, 20, 5, 5);

	Enemy otherEnemy(enemy1); 

	//realEnemy.printStats();
	//realEnemy.attack(mainCharacter);

	//realEnemy.cakeDestruct();
}