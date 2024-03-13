#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>
#include <string>

class Animal
{
protected:
	std::string type;

public:
	Animal(/* args */);
	Animal(const Animal &obj);
	virtual ~Animal();
	Animal &operator=(const Animal &obj);
	virtual void makeSound() const;
	std::string getType() const;
};

#endif
