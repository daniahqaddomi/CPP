#include "RobotomyRequestForm.hpp"
#include <cstdlib>
#include <ctime>

RobotomyRequestForm::RobotomyRequestForm() : AForm("RobotomyRequestForm", 72, 45), target("home")
{
}

RobotomyRequestForm::RobotomyRequestForm(const std::string & target)
	: AForm("RobotomyRequestForm", 72, 45), target(target)
{
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm & other)
	: AForm(other), target(other.target)
{
}

RobotomyRequestForm & RobotomyRequestForm::operator=(const RobotomyRequestForm & other)
{
	if (this != &other)
	{
		AForm::operator=(other);
		this->target = other.target;
	}
	return (*this);
}

RobotomyRequestForm::~RobotomyRequestForm()
{
}

void	RobotomyRequestForm::action() const
{
	int	luck;

	std::cout << "* drilling noises *" << std::endl;
	std::srand(static_cast<unsigned int>(std::time(NULL)));
	luck = std::rand() % 2;
	if (luck == 0)
		std::cout << this->target << " has been robotomized successfully" << std::endl;
	else
		std::cout << "robotomy of " << this->target << " failed" << std::endl;
}
