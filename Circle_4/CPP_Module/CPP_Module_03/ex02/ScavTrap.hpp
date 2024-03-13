#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include <iostream>
#include <string>
#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap
{
private:
	ScavTrap(/* args */);

public:
	ScavTrap(std::string name);
	ScavTrap(const ScavTrap &obj);
	~ScavTrap();
	ScavTrap &operator=(const ScavTrap &obj);
	void guardGate(void);
	void attack(const std::string &target);
};

#endif
