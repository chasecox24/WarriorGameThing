#include "Character.h"
#include <iostream>
#include <map>
#include <vector>

//////////////////////////////////////////////////////
Weapon::Weapon() = default;

Weapon::Weapon(std::string name, unsigned int damage, unsigned int attackTurns)
	:
	name(name),damage(damage),attackTurns(attackTurns)
{
}

int Weapon::getWeaponDamage()
{
	return damage;
}


#pragma region Character
Character::Character() = default;

Character::Character(std::string name, int health, int gold, unsigned int defense, unsigned int damage)
	:
	name(name), health(health), gold(gold), defense(defense), damage(damage)
{
}

Character::Character(std::string name, int health, int gold, const Weapon& equippedWeapon, const Armor& equippedArmor)
	:
	name(name), health(health), gold(gold), equippedWeapon(equippedWeapon),
	equippedArmor(equippedArmor)
{
}

void Character::attack(Character& enemy1)
{
	int actualDamage = damage + equippedWeapon.getWeaponDamage() - enemy1.defense;
	enemy1.health -= actualDamage;

	std::cout << "\n";
	std::cout << name << " attacked: " << enemy1.name << " for: " << actualDamage << " damage\n";
	std::cout << enemy1.name << " has: " << enemy1.health << " health left\n";

}

void Character::clone(const Character& clonedPerson)
{
	// Copies all member variables from clonedPerson into this object
	*this = clonedPerson;
}

void Character::printStats()
{
	std::cout << "\n" << "------ " << name << " STATS ------" << "\n";
	std::cout << "Name is: " << name << "\n";
	std::cout << "Damage is: " << equippedWeapon.getWeaponDamage() + damage ;
	std::cout << "\n";
	std::cout << "Defense is: " << equippedArmor.getDefenseStat() + defense ;
	std::cout << "\n";
}

#pragma endregion 

/////////////////////////////////////////////////////////////
Armor::Armor() = default;

Armor::Armor(std::string name, unsigned int defense)
	:
	name(name), 
	defense(defense)
{
}

int Armor::getDefenseStat()
{
	return defense;
}

//Enemy::Enemy(const Character& character)
//{
//	
//}

Enemy::Enemy(Character character)
{
	//gold = character.gold; 
	//character.gold = 123; 


}

Enemy::Enemy(std::string name, int health, int gold, unsigned int defense, unsigned int damage)
	:
	Character(name, health, gold, defense, damage)
{
}

//////////////////////////////////////////////////////////
void Enemy::cakeDestruct()
{
	health = 0;
	std::cout << "\n" << name << " ate the cake and died!!" << std::endl;
}

void Enemy::shapeShift(std::string animal)
{

	std::map<std::string, HPAttack> animalMap =
	{
		{"Cat", {11, 12}}
	};

	auto animalIterator = animalMap.find(animal); //finds the animal string in the map

	if (animalIterator != animalMap.end()) //past the end of the map (doesnt exist)
	{
		int healthToSet = animalIterator->second.hp; //accessing the second value mapped {HP,Attack}
		int damageToSet = animalIterator->second.attack;

		health = healthToSet;
		damage = damageToSet;
	}
	else
	{
		std::cout << "You summoned the wrong animal! CAST FAILED" << std::endl;
	}
}