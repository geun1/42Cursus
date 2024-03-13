#include "WrongCat.hpp"

WrongCat::WrongCat(/* args */) : WrongAnimal()
{
	this->type = "WrongCat";
	std::cout << "WrongCat default constructor" << std::endl;
}
WrongCat::WrongCat(const WrongCat &obj)
{
	this->type = obj.getType();
	std::cout << "WrongCat copy constructor" << std::endl;
}
WrongCat::~WrongCat()
{
	std::cout << "WrongCat destructor" << std::endl;
}
WrongCat &WrongCat::operator=(const WrongCat &obj)
{
	if (this != &obj)
	{
		this->type = obj.getType();
	}
	std::cout << "WrongCat copy assignment operator" << std::endl;
	return (*this);
}
void WrongCat::makeSound() const
{
	std::cout << "Wrong meow Wrong meow!" << std::endl;
}
