#include "Cat.hpp"
Cat::Cat(/* args */) : Animal()
{
	this->type = "Cat";
	std::cout << "Cat default constructor" << std::endl;
}
Cat::Cat(const Cat &obj)
{
	this->type = obj.getType();
	std::cout << "Cat copy constructor" << std::endl;
}
Cat::~Cat()
{
	std::cout << "Cat destructor" << std::endl;
}
Cat &Cat::operator=(const Cat &obj)
{
	if (this != &obj)
	{
		this->type = obj.getType();
	}
	std::cout << "Cat copy assignment operator" << std::endl;
	return (*this);
}
void Cat::makeSound() const
{
	std::cout << "meow meow!" << std::endl;
}
