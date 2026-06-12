#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main()
{
	Bureaucrat boss("Boss", 1);
	Bureaucrat low("Low", 150);

	ShrubberyCreationForm shrub("garden");
	RobotomyRequestForm robot("Bender");
	PresidentialPardonForm pardon("Marvin");

	std::cout << shrub << std::endl;
	std::cout << robot << std::endl;
	std::cout << pardon << std::endl;

	low.executeForm(shrub);

	boss.signForm(shrub);
	boss.signForm(robot);
	boss.signForm(pardon);

	low.executeForm(shrub);
	boss.executeForm(shrub);

	low.executeForm(robot);
	boss.executeForm(robot);

	low.executeForm(pardon);
	boss.executeForm(pardon);

	return (0);
}
