#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main(void)
{
	ScavTrap scavA("scavA");
	ScavTrap scavB("scavB");

	scavA.attack("scavB");
	scavB.takeDamage(20);
	scavB.printHitPoint();

	scavA.attack("scavB");
	scavB.takeDamage(50);
	scavB.printHitPoint();

	scavB.beRepaired(50);
	scavB.printHitPoint();

	scavB.beRepaired(10);
	scavB.guardGate();

	for (int i = 0; i < 50; i++)
	{
		scavA.beRepaired(0);
	}
	scavA.attack("a");
	scavB.beRepaired(10);
}
