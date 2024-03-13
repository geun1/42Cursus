
#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main()
{
	const Animal *meta = new Animal();
	const Animal *dog = new Dog();
	const Animal *cat = new Cat();
	std::cout << std::endl;
	std::cout << dog->getType() << " " << std::endl;
	std::cout << cat->getType() << " " << std::endl;
	std::cout << std::endl;

	dog->makeSound();
	cat->makeSound();
	meta->makeSound();
	std::cout << std::endl;

	const WrongAnimal *wrongMeta = new WrongAnimal();
	const WrongAnimal *wrongCat = new WrongCat();
	std::cout << std::endl;
	wrongMeta->makeSound();
	wrongCat->makeSound();
	std::cout << std::endl;

	delete meta;
	meta = NULL;
	std::cout << std::endl;

	delete dog;
	dog = NULL;
	std::cout << std::endl;

	delete cat;
	cat = NULL;
	std::cout << std::endl;

	delete wrongMeta;
	wrongMeta = NULL;
	std::cout << std::endl;

	delete wrongCat;
	wrongCat = NULL;
	std::cout << std::endl;

	return 0;
}
