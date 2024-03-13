#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

// #include <iostream>
#include <string>
#include "ClapTrap.hpp"

class FragTrap : public ClapTrap
{
private:
	FragTrap(/* args */);
	/* data */
public:
	FragTrap(std::string name);
	FragTrap(const FragTrap &obj);
	~FragTrap();
	FragTrap &operator=(const FragTrap &obj);
	void highFivesGuys(void);
	void attack(const std::string &target);
};

#endif
