#include "Animal.hpp"
Animal::Animal(/* args */) : type("Animal")
{
	std::cout << "Animal default constructor" << std::endl;
}
Animal::Animal(const Animal &obj)
{
	this->type = obj.getType();
	std::cout << "Animal copy constructor" << std::endl;
}
Animal::~Animal()
{
	std::cout << "Animal destructor" << std::endl;
}
Animal &Animal::operator=(const Animal &obj)
{
		if (this != &obj) {
		this->type = obj.getType();
		}
	std::cout << "Animal copy assignment operator" << std::endl;
	return (*this);
}
void Animal::makeSound() const
{
	std::cout << "metamong!" << std::endl;
}

std::string Animal::getType() const
{
	return (this->type);
}
