#include "Brain.hpp"

Brain::Brain()
{
	std::cout << "Brain turned on" << std::endl;
	for (int i = 0; i < 100; i++)
	{
		if (i % 5 == 0)
			ideas[i] = "Did I turn off the stove?";
		else
			ideas[i] = "What is the meaning of life?";
	}
}

Brain::Brain(const Brain& other)
{
	std::cout << "Brain copied" << std::endl;
	*this = other;
}

Brain& Brain::operator=(const Brain& other)
{
	if (this != &other)
	{
		for (int i = 0; i < 100; i++)
		{
			ideas[i] = other.ideas[i];
		}
	}
	return *this;
}

std::string Brain::getIdea(int index) const
{
	if (index < 0 || index >= 100)
		return ("Think outside the box");
	return (ideas[index]);
}

void Brain::setIdea(int index, std::string idea)
{
	if (index < 0 || index >= 100)
		return ;
	ideas[index] = idea;
}

Brain::~Brain()
{
	std::cout << "Brain turned off" << std::endl;
}
