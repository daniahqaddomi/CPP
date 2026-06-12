#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::AForm() : name("default"), signed_(false), gradeToSign(1), gradeToExecute(1)
{
}

AForm::AForm(const std::string & name, int gradeToSign, int gradeToExecute)
	: name(name), signed_(false), gradeToSign(gradeToSign), gradeToExecute(gradeToExecute)
{
	if (gradeToSign < 1 || gradeToExecute < 1)
		throw AForm::GradeTooHighException();
	if (gradeToSign > 150 || gradeToExecute > 150)
		throw AForm::GradeTooLowException();
}

AForm::AForm(const AForm & other)
	: name(other.name), signed_(other.signed_),
	  gradeToSign(other.gradeToSign), gradeToExecute(other.gradeToExecute)
{
}

AForm & AForm::operator=(const AForm & other)
{
	if (this != &other)
		this->signed_ = other.signed_;
	return (*this);
}

AForm::~AForm()
{
}

std::string	AForm::getName() const
{
	return (this->name);
}

bool	AForm::getSigned() const
{
	return (this->signed_);
}

int	AForm::getGradeToSign() const
{
	return (this->gradeToSign);
}

int	AForm::getGradeToExecute() const
{
	return (this->gradeToExecute);
}

void	AForm::beSigned(const Bureaucrat & b)
{
	if (b.getGrade() > this->gradeToSign)
		throw AForm::GradeTooLowException();
	this->signed_ = true;
}

void	AForm::execute(Bureaucrat const & executor) const
{
	if (this->signed_ == false)
		throw AForm::FormNotSignedException();
	if (executor.getGrade() > this->gradeToExecute)
		throw AForm::GradeTooLowException();
	this->action();
}

const char * AForm::GradeTooHighException::what() const throw()
{
	return ("Grade is too high");
}

const char * AForm::GradeTooLowException::what() const throw()
{
	return ("Grade is too low");
}

const char * AForm::FormNotSignedException::what() const throw()
{
	return ("Form is not signed");
}

std::ostream & operator<<(std::ostream & out, const AForm & f)
{
	out << "Form " << f.getName() << ", signed: ";
	if (f.getSigned() == true)
		out << "yes";
	else
		out << "no";
	out << ", sign grade required: " << f.getGradeToSign();
	out << ", exec grade required: " << f.getGradeToExecute();
	return (out);
}
