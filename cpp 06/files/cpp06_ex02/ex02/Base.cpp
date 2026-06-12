#include "Base.hpp"
#include <cstdlib>
#include <ctime>
#include <iostream>

Base::~Base()
{
}

Base	* generate(void)
{
	int	choice;

	choice = std::rand() % 3;
	if (choice == 0)
		return (new A());
	if (choice == 1)
		return (new B());
	return (new C());
}

void	identify(Base * p)
{
	if (dynamic_cast<A *>(p) != NULL)
	{
		std::cout << "A" << std::endl;
		return ;
	}
	if (dynamic_cast<B *>(p) != NULL)
	{
		std::cout << "B" << std::endl;
		return ;
	}
	if (dynamic_cast<C *>(p) != NULL)
	{
		std::cout << "C" << std::endl;
		return ;
	}
	std::cout << "Unknown" << std::endl;
}

void	identify(Base & p)
{
	if (dynamic_cast<A *>(&p) != NULL)
	{
		std::cout << "A" << std::endl;
		return ;
	}
	if (dynamic_cast<B *>(&p) != NULL)
	{
		std::cout << "B" << std::endl;
		return ;
	}
	if (dynamic_cast<C *>(&p) != NULL)
	{
		std::cout << "C" << std::endl;
		return ;
	}
	std::cout << "Unknown" << std::endl;
}
