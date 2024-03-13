#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <iostream>
#include <string>

class ClapTrap
{
protected:
	std::string name;
	unsigned int hitPoint;
	unsigned int energyPoint;
	unsigned int attackDamage;
	ClapTrap(/* args */);

public:
	ClapTrap(const ClapTrap &obj);
	virtual ~ClapTrap();
	ClapTrap &operator=(const ClapTrap &obj);

	ClapTrap(std::string name);
	virtual void attack(const std::string &target);
	void takeDamage(unsigned int amount);
	void beRepaired(unsigned int amount);
	void printHitPoint(void) const;
};

#endif
