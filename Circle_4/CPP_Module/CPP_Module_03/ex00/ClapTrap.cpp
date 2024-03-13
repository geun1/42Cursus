#include "ClapTrap.hpp"

ClapTrap::ClapTrap(/* args */)
{
	std::cout << "Clap default constructor" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &obj)
{
	this->name = obj.name;
	this->hitPoint = obj.hitPoint;
	this->energyPoint = obj.energyPoint;
	this->attackDamage = obj.attackDamage;
	std::cout << "Clap" << this->name << " copy constructor" << std::endl;
}

ClapTrap::~ClapTrap()
{
	std::cout << "Clap" << this->name << " desturctor" << std::endl;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &obj)
{
	this->name = obj.name;
	this->hitPoint = obj.hitPoint;
	this->energyPoint = obj.energyPoint;
	this->attackDamage = obj.attackDamage;
	std::cout << "Clap " << this->name << " copy assignment operator" << std::endl;
	return (*this);
}

ClapTrap::ClapTrap(std::string name) : name(name), hitPoint(10), energyPoint(10), attackDamage(0)
{
	std::cout << "Clap " << this->name << " constructor" << std::endl;
}

void ClapTrap::attack(const std::string &target)
{
	if (!this->hitPoint || !this->energyPoint)
		std::cout << this->name << " can't attack" << std::endl;
	else
	{
		std::cout << "ClapTrap " << this->name << " attacks " << target << ", causing " << this->attackDamage << " points of damage!" << std::endl;

		this->energyPoint--;
	}
}

void ClapTrap::takeDamage(unsigned int amount)
{
	if (this->hitPoint < amount)
		this->hitPoint = 0;
	else
	{
		this->hitPoint -= amount;
		std::cout << this->name << " is hit as hard as " << amount << std::endl;
	}
	if (!this->hitPoint)
		std::cout << this->name << " is died" << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (!this->hitPoint)
		std::cout << this->name << " is already died..." << std::endl;
	else if (!this->energyPoint)
		std::cout << this->name << " don't have energy" << std::endl;
	else
	{
		std::cout << this->name << " is repaired about " << amount << "..!" << std::endl;
		this->hitPoint += amount;
		this->energyPoint--;
	}
}
void ClapTrap::printHitPoint(void) const
{
	std::cout << this->name << "'s hit point: " << this->hitPoint << std::endl;
}
