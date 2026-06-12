#include "Bureaucrat.hpp"
#include "Intern.hpp"

int main()
{
	Intern		someRandomIntern;
	AForm		* rrf;
	Bureaucrat	boss("Boss", 1);

	rrf = someRandomIntern.makeForm("robotomy request", "Bender");
	if (rrf != NULL)
	{
		boss.signForm(*rrf);
		boss.executeForm(*rrf);
		delete rrf;
	}

	AForm	* shrub = someRandomIntern.makeForm("shrubbery creation", "yard");
	if (shrub != NULL)
	{
		boss.signForm(*shrub);
		boss.executeForm(*shrub);
		delete shrub;
	}

	AForm	* pardon = someRandomIntern.makeForm("presidential pardon", "Marvin");
	if (pardon != NULL)
	{
		boss.signForm(*pardon);
		boss.executeForm(*pardon);
		delete pardon;
	}

	AForm	* bad = someRandomIntern.makeForm("does not exist", "nowhere");
	if (bad != NULL)
		delete bad;

	return (0);
}
