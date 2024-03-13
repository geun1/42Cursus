#include "ClapTrap.hpp"

int main(void)
{
	ClapTrap clap("clap");

	clap.attack("air");
	clap.attack("air");
	clap.attack("air");
	clap.attack("air");
	clap.attack("air");
	clap.attack("air");

	clap.takeDamage(5);
	clap.printHitPoint();

	clap.beRepaired(4);
	clap.printHitPoint();

	clap.attack("himself");

	clap.takeDamage(5);
	clap.printHitPoint();

	clap.beRepaired(1);
	clap.attack("air");
	clap.attack("air");
	clap.attack("air");

	clap.takeDamage(5);
}
