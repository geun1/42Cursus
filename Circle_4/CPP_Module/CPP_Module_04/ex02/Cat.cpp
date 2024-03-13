#include "Cat.hpp"
Cat::Cat(/* args */) : Animal()
{
	this->type = "Cat";
	this->brain = new Brain();
	std::cout << "Cat default constructor" << std::endl;
}
Cat::Cat(const Cat &obj)
{
	this->type = obj.getType();
	this->brain = new Brain(*obj.getBrain());
	std::cout << "Cat copy constructor" << std::endl;
}
Cat::~Cat()
{
	delete this->brain;
	std::cout << "Cat destructor" << std::endl;
}
Cat &Cat::operator=(const Cat &obj)
{
	if (this != &obj)
	{

		this->type = obj.getType();
		this->brain = new Brain(*obj.getBrain());
	}
	std::cout << "Cat copy assignment operator" << std::endl;
	return (*this);
}
void Cat::makeSound() const
{
	std::cout << "meow meow!" << std::endl;
}

Brain *Cat::getBrain() const
{
	return this->brain;
}
