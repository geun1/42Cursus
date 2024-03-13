#ifndef CAT_HPP
#define CAT_HPP

#include <iostream>
#include <string>
#include "Animal.hpp"

class Cat : public Animal
{
public:
	Cat(/* args */);
	Cat(const Cat &obj);
	~Cat();
	Cat &operator=(const Cat &obj);

	void makeSound() const;
};

#endif
