#include "Base.hpp"

int main() {
    Base* random = generate();
    if (random) {
        identify(random);
        identify(*random);
        delete random;
    }
	system("leaks a.out");
    return 0;
}
