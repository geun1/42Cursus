#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <iostream>
#include <string>

class Brain
{
private:
	std::string ideas[100];

public:
	Brain(/* args */);
	Brain(const Brain &obj);
	~Brain();
	Brain &operator=(const Brain &obj);
	std::string getIdeas(int n) const;
	void setIdeas(std::string idea, int n);
};

#endif
