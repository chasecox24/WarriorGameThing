#pragma once

#include <string>
#include <map>
#include <vector>

struct HPAttack
{
	int hp;
	int attack;
};

//Weapon
class Weapon
{
	std::string name = "";
	unsigned int damage = 0;
	unsigned int attackTurns = 0;

public:
	Weapon();
	Weapon(std::string name, unsigned int damage, unsigned int attackTurns);

	//getter
	int getWeaponDamage() const;

};

//Armor
class Armor
{
	std::string name;
	unsigned int defense = 0;

public:
	//constructor
	Armor();
	Armor(std::string name, unsigned int defense);


	//getter
	int getDefenseStat() const;
};


class Character
{

protected:
	std::string name = "";
	unsigned int health = 0;
	unsigned int gold = 0;

	Weapon equippedWeapon;
	Armor equippedArmor;

	unsigned int damage = equippedWeapon.getWeaponDamage() || 0;
	unsigned int defense = equippedArmor.getDefenseStat() || 0;

public:
	//constructors
	Character();
	Character(std::string name, int health, int gold, unsigned int defense, unsigned int damage);
	Character(std::string name, int health, int gold, const Weapon& equippedWeapon, const Armor& equippedArmor );

	//setters
	void setCharacterEquippedWeapon(const Weapon& weapon);
	void setCharacterEquippedArmor(const Armor& armor);

	//functions
	void attack(Character& enemy1);
	void takeSpellDamage(int damageTaken);
	Character clone(const Character& clonedPerson); //will return a new character so use the = operator to assign it to a new character object.
	void printStats();
};

class Enemy : public Character
{
	//using Character::Character; inherit all constructors from the base class Character.
private:
	// Since animalMap is now a member variable inside the Enemy class, 
	// shapeShift already has direct access to it.
	std::map<std::string, HPAttack> animalMap =
	{
		{"Cat", {120, 15}},
		{"Dog", {100, 10}},
		{"Dragon", {200, 25}},
		{"Unicorn", {180, 20}},
		{"Bear", {250, 18}},
	};

	std::map<std::string, unsigned int> spellMap =
	{
		{"Fireball", 30},
		{"Ice Spike", 20},
		{"Lightning Bolt", 25},
		{"Stinky Cloud", 50},
	};

public:
	
	Enemy(Character character);
	Enemy(std::string name, int health, int gold, unsigned int defense, unsigned int damage);

	void cakeDestruct();
	void shapeShift(std::string animal);
	void castSpell(std::string spellName, Character& target);
};