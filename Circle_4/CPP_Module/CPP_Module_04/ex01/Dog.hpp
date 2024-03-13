#ifndef DOG_CPP
#define DOG_CPP

#include <iostream>
#include <string>
#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public Animal
{
private:
	Brain *brain;

public:
	Dog(/* args */);
	Dog(const Dog &obj);
	~Dog();
	Dog &operator=(const Dog &obj);

	void makeSound() const;
	Brain *getBrain() const;
};

#endif
