#pragma once

#include<array>
#include <string>

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
	int getWeaponDamage();

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
	int getDefenseStat();
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


	//functions
	void attack(Character& enemy1);
	void clone(const Character& clonedPerson);
	void printStats();
};

class Enemy : public Character
{
	//using Character::Character;

public:

	Enemy(Character character);
	Enemy(std::string name, int health, int gold, unsigned int defense, unsigned int damage);

	void cakeDestruct();
	void shapeShift(std::string animal);
	void castSpell(int spellNumber);

};