#include "Bureaucrat.hpp"

int main()
{
	try
	{
		Bureaucrat a("Marvin", 1);
		std::cout << a << std::endl;
		a.increment();
	}
	catch (std::exception & e)
	{
		std::cout << "Error: " << e.what() << std::endl;
	}

	try
	{
		Bureaucrat b("Trillian", 150);
		std::cout << b << std::endl;
		b.decrement();
	}
	catch (std::exception & e)
	{
		std::cout << "Error: " << e.what() << std::endl;
	}

	try
	{
		Bureaucrat c("Zaphod", 0);
		std::cout << c << std::endl;
	}
	catch (std::exception & e)
	{
		std::cout << "Error: " << e.what() << std::endl;
	}

	try
	{
		Bureaucrat d("Ford", 151);
		std::cout << d << std::endl;
	}
	catch (std::exception & e)
	{
		std::cout << "Error: " << e.what() << std::endl;
	}

	return (0);
}
