#include "Base.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>

int main()
{
	std::srand(static_cast<unsigned int>(std::time(NULL)));

	int	i;

	i = 0;
	while (i < 6)
	{
		Base	* p;

		p = generate();
		std::cout << "pointer says: ";
		identify(p);
		std::cout << "reference says: ";
		identify(*p);
		std::cout << "------" << std::endl;
		delete p;
		i++;
	}
	return (0);
}
