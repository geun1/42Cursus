#ifndef WRONGANIMAL_HPP
#define WRONGANIMAL_HPP

#include <iostream>
#include <string>

class WrongAnimal
{
protected:
	std::string type;

public:
	WrongAnimal(/* args */);
	WrongAnimal(const WrongAnimal &obj);
	virtual ~WrongAnimal();
	WrongAnimal &operator=(const WrongAnimal &obj);
	void makeSound() const;
	std::string getType() const;
};

#endif
