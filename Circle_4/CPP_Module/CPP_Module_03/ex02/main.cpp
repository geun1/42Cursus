#include "ClapTrap.hpp"
#include "FragTrap.hpp"

int main(void)
{
	FragTrap FragA("FragA");
	FragTrap FragB("FragB");
	for (int j = 0; j < 3; j++)
	{

		FragA.attack("FragB");
		FragB.takeDamage(30);
		FragB.printHitPoint();
		FragB.attack("the air");
	}

	FragB.beRepaired(50);
	FragB.printHitPoint();
	FragB.beRepaired(50);
	FragB.printHitPoint();

	FragB.beRepaired(10);
	FragB.printHitPoint();
	FragB.highFivesGuys();
	FragB.beRepaired(10);
	FragB.printHitPoint();
}
