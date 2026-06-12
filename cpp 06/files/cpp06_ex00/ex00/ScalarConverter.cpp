#include "ScalarConverter.hpp"
#include <cstdlib>
#include <cmath>
#include <climits>
#include <cfloat>
#include <iomanip>

ScalarConverter::ScalarConverter()
{
}

ScalarConverter::ScalarConverter(const ScalarConverter & other)
{
	(void)other;
}

ScalarConverter & ScalarConverter::operator=(const ScalarConverter & other)
{
	(void)other;
	return (*this);
}

ScalarConverter::~ScalarConverter()
{
}

static bool	isCharLiteral(const std::string & str)
{
	if (str.size() == 1 && std::isdigit(static_cast<unsigned char>(str[0])) == 0)
		return (true);
	return (false);
}

static bool	isIntLiteral(const std::string & str)
{
	size_t	i;
	size_t	len;

	i = 0;
	len = str.size();
	if (len == 0)
		return (false);
	if (str[0] == '+' || str[0] == '-')
		i = 1;
	if (i == len)
		return (false);
	while (i < len)
	{
		if (std::isdigit(static_cast<unsigned char>(str[i])) == 0)
			return (false);
		i++;
	}
	return (true);
}

static bool	isFloatLiteral(const std::string & str)
{
	size_t	len;

	len = str.size();
	if (len == 0)
		return (false);
	if (str[len - 1] != 'f')
		return (false);
	if (str == "f" || str == "+f" || str == "-f")
		return (false);
	if (str == "nanf" || str == "+inff" || str == "-inff")
		return (true);

	std::string	body;
	size_t		i;
	bool		dotFound;

	body = str.substr(0, len - 1);
	i = 0;
	dotFound = false;
	if (body[0] == '+' || body[0] == '-')
		i = 1;
	if (i == body.size())
		return (false);
	while (i < body.size())
	{
		if (body[i] == '.')
		{
			if (dotFound == true)
				return (false);
			dotFound = true;
		}
		else if (std::isdigit(static_cast<unsigned char>(body[i])) == 0)
			return (false);
		i++;
	}
	if (dotFound == false)
		return (false);
	return (true);
}

static bool	isDoubleLiteral(const std::string & str)
{
	size_t	i;
	bool	dotFound;

	if (str == "nan" || str == "+inf" || str == "-inf")
		return (true);
	i = 0;
	dotFound = false;
	if (str.size() == 0)
		return (false);
	if (str[0] == '+' || str[0] == '-')
		i = 1;
	if (i == str.size())
		return (false);
	while (i < str.size())
	{
		if (str[i] == '.')
		{
			if (dotFound == true)
				return (false);
			dotFound = true;
		}
		else if (std::isdigit(static_cast<unsigned char>(str[i])) == 0)
			return (false);
		i++;
	}
	if (dotFound == false)
		return (false);
	return (true);
}

static void	printChar(double value)
{
	if (std::isnan(value) || std::isinf(value))
	{
		std::cout << "char: impossible" << std::endl;
		return ;
	}
	if (value < 0 || value > 127)
	{
		std::cout << "char: impossible" << std::endl;
		return ;
	}
	char	c;

	c = static_cast<char>(value);
	if (std::isprint(static_cast<unsigned char>(c)) == 0)
		std::cout << "char: Non displayable" << std::endl;
	else
		std::cout << "char: '" << c << "'" << std::endl;
}

static void	printInt(double value)
{
	if (std::isnan(value) || std::isinf(value))
	{
		std::cout << "int: impossible" << std::endl;
		return ;
	}
	if (value < static_cast<double>(INT_MIN) || value > static_cast<double>(INT_MAX))
	{
		std::cout << "int: impossible" << std::endl;
		return ;
	}
	std::cout << "int: " << static_cast<int>(value) << std::endl;
}

static void	printFloat(double value)
{
	std::cout << "float: ";
	if (std::isnan(value))
	{
		std::cout << "nanf" << std::endl;
		return ;
	}
	if (std::isinf(value))
	{
		if (value > 0)
			std::cout << "+inff" << std::endl;
		else
			std::cout << "-inff" << std::endl;
		return ;
	}
	float	f;

	f = static_cast<float>(value);
	std::cout << std::fixed << std::setprecision(1) << f << "f" << std::endl;
}

static void	printDouble(double value)
{
	std::cout << "double: ";
	if (std::isnan(value))
	{
		std::cout << "nan" << std::endl;
		return ;
	}
	if (std::isinf(value))
	{
		if (value > 0)
			std::cout << "+inf" << std::endl;
		else
			std::cout << "-inf" << std::endl;
		return ;
	}
	std::cout << std::fixed << std::setprecision(1) << value << std::endl;
}

void	ScalarConverter::convert(const std::string & literal)
{
	double	value;

	if (isCharLiteral(literal) == true)
	{
		value = static_cast<double>(static_cast<int>(literal[0]));
	}
	else if (isIntLiteral(literal) == true)
	{
		value = std::strtod(literal.c_str(), NULL);
	}
	else if (isFloatLiteral(literal) == true)
	{
		if (literal == "nanf")
			value = std::strtod("nan", NULL);
		else if (literal == "+inff")
			value = std::strtod("inf", NULL);
		else if (literal == "-inff")
			value = std::strtod("-inf", NULL);
		else
			value = std::strtod(literal.c_str(), NULL);
	}
	else if (isDoubleLiteral(literal) == true)
	{
		if (literal == "nan")
			value = std::strtod("nan", NULL);
		else if (literal == "+inf")
			value = std::strtod("inf", NULL);
		else if (literal == "-inf")
			value = std::strtod("-inf", NULL);
		else
			value = std::strtod(literal.c_str(), NULL);
	}
	else
	{
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: impossible" << std::endl;
		std::cout << "double: impossible" << std::endl;
		return ;
	}

	printChar(value);
	printInt(value);
	printFloat(value);
	printDouble(value);
}
