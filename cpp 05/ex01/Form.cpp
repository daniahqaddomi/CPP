#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form() : name("default"), signed_(false), gradeToSign(1), gradeToExecute(1)
{
}

Form::Form(const std::string & name, int gradeToSign, int gradeToExecute)
	: name(name), signed_(false), gradeToSign(gradeToSign), gradeToExecute(gradeToExecute)
{
	if (gradeToSign < 1 || gradeToExecute < 1)
		throw Form::GradeTooHighException();
	if (gradeToSign > 150 || gradeToExecute > 150)
		throw Form::GradeTooLowException();
}

Form::Form(const Form & other)
	: name(other.name), signed_(other.signed_),
	  gradeToSign(other.gradeToSign), gradeToExecute(other.gradeToExecute)
{
}

Form & Form::operator=(const Form & other)
{
	if (this != &other)
		this->signed_ = other.signed_;
	return (*this);
}

Form::~Form()
{
}

std::string	Form::getName() const
{
	return (this->name);
}

bool	Form::getSigned() const
{
	return (this->signed_);
}

int	Form::getGradeToSign() const
{
	return (this->gradeToSign);
}

int	Form::getGradeToExecute() const
{
	return (this->gradeToExecute);
}

void	Form::beSigned(const Bureaucrat & b)
{
	if (b.getGrade() > this->gradeToSign)
		throw Form::GradeTooLowException();
	this->signed_ = true;
}

const char * Form::GradeTooHighException::what() const throw()
{
	return ("Grade is too high");
}

const char * Form::GradeTooLowException::what() const throw()
{
	return ("Grade is too low");
}

std::ostream & operator<<(std::ostream & out, const Form & f)
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
