#ifndef DOG_CPP
#define DOG_CPP

#include <iostream>
#include <string>
#include "Animal.hpp"

class Dog : public Animal
{
public:
	Dog(/* args */);
	Dog(const Dog &obj);
	~Dog();
	Dog &operator=(const Dog &obj);

	void makeSound() const;
};

#endif
