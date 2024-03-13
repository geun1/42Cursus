#include "ScavTrap.hpp"

ScavTrap::ScavTrap(/* args */)
{
	std::cout << "Scav " << this->name << "default constructor" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &obj)
{
	this->name = obj.name;
	this->hitPoint = obj.hitPoint;
	this->energyPoint = obj.energyPoint;
	this->attackDamage = obj.attackDamage;
	std::cout << "Scav " << this->name << " copy constructor" << std::endl;
}

ScavTrap::~ScavTrap()
{
	std::cout << "Scav " << this->name << " desturctor" << std::endl;
}

ScavTrap &ScavTrap::operator=(const ScavTrap &obj)
{
	this->name = obj.name;
	this->hitPoint = obj.hitPoint;
	this->energyPoint = obj.energyPoint;
	this->attackDamage = obj.attackDamage;
	std::cout << "Scav " << this->name << " copy assignment operator" << std::endl;
	return (*this);
}

ScavTrap::ScavTrap(std::string name)
{
	this->name = name;
	this->hitPoint = 100;
	this->energyPoint = 50;
	this->attackDamage = 20;
	std::cout << "Scav " << this->name << " constructor" << std::endl;
}

void ScavTrap::guardGate(void)
{
	if (!this->hitPoint)
		std::cout << this->name << " can't attack..." << std::endl;
	else
	{
		std::cout << this->name << " is converted to gate guard mode...!" << std::endl;
	}
}

void ScavTrap::attack(const std::string &target)
{
	if (!this->hitPoint || !this->energyPoint)
		std::cout << this->name << " can't attack!!!" << std::endl;
	else
	{
		std::cout << "SC4V-TP " << this->name << " hits " << target << ", causing " << this->attackDamage << " points of damage!" << std::endl;
		this->energyPoint--;
	}
}
