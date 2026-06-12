#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
	Bureaucrat strongGuy("StrongGuy", 1);
	Bureaucrat weakGuy("WeakGuy", 150);
	Form form("tax form", 50, 25);

	std::cout << form << std::endl;

	weakGuy.signForm(form);
	std::cout << form << std::endl;

	strongGuy.signForm(form);
	std::cout << form << std::endl;

	try
	{
		Form badForm("bad form", 0, 1);
		std::cout << badForm << std::endl;
	}
	catch (std::exception & e)
	{
		std::cout << "Error: " << e.what() << std::endl;
	}

	return (0);
}
