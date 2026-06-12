#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

Intern::Intern()
{
}

Intern::Intern(const Intern & other)
{
	(void)other;
}

Intern & Intern::operator=(const Intern & other)
{
	(void)other;
	return (*this);
}

Intern::~Intern()
{
}

AForm	* Intern::makeForm(const std::string & name, const std::string & target)
{
	std::string	formNames[3];
	AForm		* newForm;
	int			i;

	formNames[0] = "shrubbery creation";
	formNames[1] = "robotomy request";
	formNames[2] = "presidential pardon";

	newForm = NULL;
	i = 0;
	while (i < 3)
	{
		if (formNames[i] == name)
		{
			if (i == 0)
				newForm = new ShrubberyCreationForm(target);
			if (i == 1)
				newForm = new RobotomyRequestForm(target);
			if (i == 2)
				newForm = new PresidentialPardonForm(target);
			break;
		}
		i++;
	}
	if (newForm == NULL)
	{
		std::cout << "Intern could not find form: " << name << std::endl;
		return (NULL);
	}
	std::cout << "Intern creates " << name << std::endl;
	return (newForm);
}
