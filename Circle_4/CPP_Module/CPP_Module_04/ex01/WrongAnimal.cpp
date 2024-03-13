#include "WrongAnimal.hpp"
WrongAnimal::WrongAnimal(/* args */) : type("WrongAnimal")
{
	std::cout << "WrongAnimal default constructor" << std::endl;
}
WrongAnimal::WrongAnimal(const WrongAnimal &obj)
{
	this->type = obj.getType();
	std::cout << "WrongAnimal copy constructor" << std::endl;
}
WrongAnimal::~WrongAnimal()
{
	std::cout << "WrongAnimal destructor" << std::endl;
}
WrongAnimal &WrongAnimal::operator=(const WrongAnimal &obj)
{
		if (this != &obj) {
	this->type = obj.getType();
		}
	std::cout << "WrongAnimal copy assignment operator" << std::endl;
	return (*this);
}
void WrongAnimal::makeSound() const
{
	std::cout << "Wrong Wrong!" << std::endl;
}

std::string WrongAnimal::getType() const
{
	return (this->type);
}
