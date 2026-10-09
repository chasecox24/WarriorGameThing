#include <iostream>
#include <limits>

#include "Game.h"
#include "Character.h"

Game::Game() = default;

void Game::startGame()
{
	std::cout << "Starting game setup...\n";
	std::cout << "Press ENTER to continue...\n\n";
	std::cout << "If you press characters before pressing ENTER, it will be used as your character name.\n";
	std::cout << "--------------------------------------------------------------------------------------------\n";

	std::cin.get();
	
	//playerCharacter, Weapon, Armor creation
	playerCharacter = createPlayerCharacter(); //setting the private member variable playerCharacter inside the Game class
	Weapon starterWeapon = selectStarterWeapon(); //create the starter weapon and assign it to a variable we will use to assign to the playerCharacter

	playerCharacter.setCharacterEquippedWeapon(starterWeapon); //assign the selected weapon to the player's equipped weapon
	
	Armor starterArmor = selectStarterArmor(); //create the starter armor and assign it to a variable we will use to assign to the playerCharacter
	playerCharacter.setCharacterEquippedArmor(starterArmor); //assign the selected armor to the player's

	playerCharacter.printStats();
	
	// Start the main game loop
	gameLoop();
}

void Game::gameLoop()
{

}

Character Game::createPlayerCharacter()
{
	std::system("cls"); //clear console screen, only on Windows

	std::string name;
	int health = 100, gold = 50, defense = 0, damage = 0; //putting default values on the same line can be done like this
	std::cout << "Enter Character Name: ";
	std::getline(std::cin, name);
	
	Character playerCharacter(name, health, gold, defense, damage); //make a character using the character constructor and initialize it with the values above.
	playerCharacter.printStats();
	return playerCharacter;
}

Weapon Game::selectStarterWeapon()
{
	std::system("cls");

	std::cout << "---------Select Your Weapon---------\n";
	std::cout << "====================================\n";
	std::cout << "1. Iron Broadsword  (Damage: 18)\n";
	std::cout << "2. Longbow          (Damage: 14)\n";
	std::cout << "3. Apprentice Staff (Damage: 12)\n";
	std::cout << "Choose your starter weapon (1-3): ";

	int choice;
	std::cin >> choice;

	std::string weaponName = "Dummy Weapon";
	int weaponDamage = 1;
	int attackTurns = 1; //not implemented yet, idk if I want this

	switch (choice) // case switch statement
	{
	case 1:
		weaponName = "Iron Broadsword";
		weaponDamage = 18;
		break;
	case 2:
		weaponName = "Longbow";
		weaponDamage = 14;
		break;
	case 3:
		weaponName = "Apprentice Staff";
		weaponDamage = 12;
		break;
	default:
		std::cout << "Invalid choice. Defaulting to Dummy Weapon.\n";
		break;
	}

	std::cout << "You equipped the " << weaponName << "!\n\n";

	waitForInput();
	return Weapon(weaponName, weaponDamage, attackTurns);
}

Armor Game::selectStarterArmor()
{
	std::system("cls");

	std::cout << "---------Select Your Armor---------\n";
	std::cout << "===================================\n";
	std::cout << "1. Iron Plate Armor  (Defense: 10)\n";
	std::cout << "2. Leather Mail     (Defense: 5)\n";
	std::cout << "3. Robe of Wisdom   (Defense: 3)\n";
	std::cout << "Choose your starter armor (1-3): ";

	int choice = 0;
	std::cin >> choice;

	std::string armorName = "Dummy Armor";
	int defenseStat = 0;

	switch (choice)
	{
	case 1:
		armorName = "Iron Plate Armor";
		defenseStat = 10;
		break;
	case 2:
		armorName = "Leather Mail";
		defenseStat = 5;
		break;
	case 3:
		armorName = "Robe of Wisdom";
		defenseStat = 3;
		break;
	default:
		std::cout << "Invalid choice! Defaulting to Dummy Armor.\n";
		break;
	}

	std::cout << "You equipped the " << armorName << "!\n\n";

	waitForInput();
	return Armor(armorName, defenseStat);
}

Weapon Game::createWeapon()
{
	std::string weaponName;
	int weaponDamage = 0;
	int attackTurns = 1; //not implemented yet, idk if I want this

	std::cout << "Enter weapon name: ";
	std::getline(std::cin, weaponName);

	

	return Weapon(weaponName, weaponDamage, attackTurns);
}

Armor Game::createArmor()
{
	std::string armorName;
	int armorDefense = 0;
	
	std::cout << "Enter armor name: ";
	std::getline(std::cin, armorName);

	//make the armorDefense a random number depending on the name length of armorName
	armorDefense = rand() % (armorName.length() + 1);

	//add a radom before and after name on the armorName to make it more interesting



	return Armor(armorName, armorDefense);
}

void Game::waitForInput() //this thing is TRASH and takes the previous characters inputted
{
	std::cout << "\nPress Enter to continue..." << std::endl;

	// Clear out any remaining characters in the buffer
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

	// Wait for the user to press Enter
	std::cin.get();
}
