#ifndef WRONGCAT_HPP
#define WRONGCAT_HPP

#include "WrongAnimal.hpp"
#include <iostream>
#include <string>

class WrongCat : public WrongAnimal
{
public:
	WrongCat(/* args */);
	WrongCat(const WrongCat &obj);
	~WrongCat();
	WrongCat &operator=(const WrongCat &obj);
	void makeSound() const;
};

#endif
