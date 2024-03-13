#include "BitcoinExchange.hpp"

int main(int ac, char **av) {
	try {
		checkArg(ac, av);
		btc("data.csv", av[1]);
	}
	catch(const std::exception& e) {
		std::cerr <<  e.what() << std::endl;
	}
	// system("leaks btc");
	return 0;
}