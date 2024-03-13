#include "FragTrap.hpp"

FragTrap::FragTrap(/* args */)
{
	std::cout << "Frag " << this->name << "default constructor" << std::endl;
}

FragTrap::FragTrap(const FragTrap &obj)
{
	this->name = obj.name;
	this->hitPoint = obj.hitPoint;
	this->energyPoint = obj.energyPoint;
	this->attackDamage = obj.attackDamage;
	std::cout << "Frag " << this->name << " copy constructor" << std::endl;
}

FragTrap::~FragTrap()
{
	std::cout << "Frag " << this->name << " desturctor" << std::endl;
}

FragTrap &FragTrap::operator=(const FragTrap &obj)
{
	this->name = obj.name;
	this->hitPoint = obj.hitPoint;
	this->energyPoint = obj.energyPoint;
	this->attackDamage = obj.attackDamage;
	std::cout << "Frag " << this->name << " copy assignment operator" << std::endl;
	return (*this);
}

FragTrap::FragTrap(std::string name)
{
	this->name = name;
	this->hitPoint = 100;
	this->energyPoint = 100;
	this->attackDamage = 30;
	std::cout << "Frag " << this->name << " constructor" << std::endl;
}

void FragTrap::highFivesGuys(void)
{
	if (!this->hitPoint)
		std::cout << this->name << " can't be converted" << std::endl;
	else
		std::cout << this->name << " says high Fives~" << std::endl;
}

void FragTrap::attack(const std::string &target)
{
	if (!this->hitPoint || !this->energyPoint)
		std::cout << this->name << " can't attack!!!" << std::endl;
	else
	{
		std::cout << "GaeGull " << this->name << " hits " << target << ",causing " << this->attackDamage << " points of damage!" << std::endl;
		this->energyPoint--;
	}
}
