#include "Brain.hpp"

Brain::Brain(/* args */)
{
	std::cout << "Brain constructor" << std::endl;
	for (int i = 0; i < 100; i++)
	{
		this->ideas[i] = "Blah blah";
	}
}
Brain::Brain(const Brain &obj)
{
	std::cout << "Brain copy constructor" << std::endl;
	for (int i = 0; i < 100; i++)
	{
		this->setIdeas(obj.getIdeas(i), i);
	}
}
Brain::~Brain()
{
	std::cout << "Brain destructor" << std::endl;
}
Brain &Brain::operator=(const Brain &obj)
{
	if (this != &obj)
	{

		for (int i = 0; i < 100; i++)
		{
			this->setIdeas(obj.getIdeas(i), i);
		}
	}
	std::cout << "Brain copy assignment operator" << std::endl;
	return *this;
}
std::string Brain::getIdeas(int n) const
{

	return this->ideas[n];
}
void Brain::setIdeas(std::string idea, int n)
{

	this->ideas[n] = idea;
}
