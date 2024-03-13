#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main(void)
{
	std::string str;
	Animal *meta[10];

	// Animal *animal = new Animal();
	for (int i = 0; i < 5; i++)
	{
		meta[i] = new Dog();
		std::cout << std::endl;
	}
	for (int i = 5; i < 10; i++)
	{
		meta[i] = new Cat();
		std::cout << std::endl;
	}
	std::cout << std::endl;
	for (int i = 0; i < 10; i++)
	{
		delete meta[i];
		std::cout << std::endl;
	}
	std::cout << std::endl;

	Dog *d = new Dog();
	Dog *d2 = new Dog();

	std::cout << std::endl;

	str = d->getBrain()->getIdeas(0);
	std::cout << "Dog1's first idea is " << str << std::endl;

	d->getBrain()->setIdeas("something", 0);
	str = d->getBrain()->getIdeas(0);
	std::cout << "Dog1's first idea is " << str << std::endl;

	*d2 = *d;
	str = d2->getBrain()->getIdeas(0);
	std::cout << "Dog2's first idea is " << str << std::endl;

	std::cout << std::endl;
	delete d;
	d = NULL;
	std::cout << std::endl;
	delete d2;
	d2 = NULL;
	return 0;
}
