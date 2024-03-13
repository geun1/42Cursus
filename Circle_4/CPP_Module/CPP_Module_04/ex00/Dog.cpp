#include "Dog.hpp"
Dog::Dog(/* args */) : Animal()
{
	this->type = "Dog";
	std::cout << "Dog default constructor" << std::endl;
}
Dog::Dog(const Dog &obj)
{
	this->type = obj.getType();
	std::cout << "Dog copy constructor" << std::endl;
}
Dog::~Dog()
{
	std::cout << "Dog destructor" << std::endl;
}
Dog &Dog::operator=(const Dog &obj)
{
	if (this != &obj)
	{
		this->type = obj.getType();
	}
	std::cout << "Dog copy assignment operator" << std::endl;
	return (*this);
}
void Dog::makeSound() const
{
	std::cout << "wall wall!" << std::endl;
}
