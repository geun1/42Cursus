#include "PmergeMe.hpp"

int main(int ac, char **av) {
	try {
		checkErrors(ac, av);
		sort(ac - 1, av);
	}
	catch(const std::invalid_argument &e) {
		std::cerr << e.what() << '\n';
	}
	return 0;
}