#include "RPN.hpp"

int	main(int ac, char **av) {
	try {
		checkArgumentErrors(ac, av[1], 0);
		rpn(av[1], 0);
	}
	catch(const std::exception& e) {
		std::cerr << e.what() << std::endl;
	}
	return 0;
}