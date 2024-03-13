#include "Dog.hpp"
Dog::Dog(/* args */) : Animal()
{
	this->type = "Dog";
	this->brain = new Brain();
	std::cout << "Dog default constructor" << std::endl;
}
Dog::Dog(const Dog &obj)
{
	this->type = obj.getType();
	this->brain = new Brain(*obj.getBrain());
	std::cout << "Dog copy constructor" << std::endl;
}
Dog::~Dog()
{
	delete this->brain;
	std::cout << "Dog destructor" << std::endl;
}
Dog &Dog::operator=(const Dog &obj)
{
	if (this != &obj)
	{

		this->type = obj.getType();
		this->brain = new Brain(*obj.getBrain());
	}
	std::cout << "Dog copy assignment operator" << std::endl;
	return (*this);
}
void Dog::makeSound() const
{
	std::cout << "wall wall!" << std::endl;
}
Brain *Dog::getBrain() const
{
	return this->brain;
}
