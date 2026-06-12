#include <iostream>
#include <string>
#include "iter.hpp"

template <typename T>
void	print(T & elem)
{
	std::cout << elem << " ";
}

template <typename T>
void	printConst(T const & elem)
{
	std::cout << elem << " ";
}

template <typename T>
void	doubleIt(T & elem)
{
	elem = elem * 2;
}

int main(void)
{
	int	tab[5] = {1, 2, 3, 4, 5};

	std::cout << "int array before: ";
	iter(tab, static_cast<size_t>(5), print<int>);
	std::cout << std::endl;

	iter(tab, static_cast<size_t>(5), doubleIt<int>);
	std::cout << "int array after doubling: ";
	iter(tab, static_cast<size_t>(5), print<int>);
	std::cout << std::endl;

	int const tabConst[3] = {10, 20, 30};

	std::cout << "const int array: ";
	iter(tabConst, static_cast<size_t>(3), printConst<int>);
	std::cout << std::endl;

	std::string	words[3] = {"foo", "bar", "baz"};

	std::cout << "string array: ";
	iter(words, static_cast<size_t>(3), print<std::string>);
	std::cout << std::endl;

	return (0);
}
