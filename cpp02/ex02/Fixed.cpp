/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniah <daniah@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/22 00:00:02 by daniah            #+#    #+#             */
/*   Updated: 2026/01/10 00:02:08 by daniah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <cmath>

Fixed::Fixed()
{
	this->value = 0;
}

Fixed::Fixed(const int n)
{
	this->value = n << this->bits;
}

Fixed::Fixed(const float f)
{
	this->value = roundf(f * (1 << this->bits));
}

Fixed::Fixed(const Fixed& other)
{
	*this = other;
}

Fixed& Fixed::operator=(const Fixed& other)
{
	if (this != &other)
	{
		this->value = other.getRawBits();
	}
	return *this;
}

Fixed::~Fixed()
{
}

int Fixed::getRawBits(void) const
{
	return this->value;
}

void Fixed::setRawBits(int const raw)
{
	this->value = raw;
}

float Fixed::toFloat(void) const
{
	return (float)this->value / (1 << this->bits);
}

int Fixed::toInt(void) const
{
	return this->value >> this->bits;
}

bool Fixed::operator>(const Fixed& other) const
{
	return this->value > other.value;
}

bool Fixed::operator<(const Fixed& other) const
{
	return this->value < other.value;
}

bool Fixed::operator>=(const Fixed& other) const
{
	return this->value >= other.value;
}

bool Fixed::operator<=(const Fixed& other) const
{
	return this->value <= other.value;
}

bool Fixed::operator==(const Fixed& other) const
{
	return this->value == other.value;
}

bool Fixed::operator!=(const Fixed& other) const
{
	return this->value != other.value;
}

Fixed Fixed::operator+(const Fixed& other) const
{
	Fixed result;
	result.setRawBits(this->value + other.value);
	return result;
}

Fixed Fixed::operator-(const Fixed& other) const
{
	Fixed result;
	result.setRawBits(this->value - other.value);
	return result;
}

Fixed Fixed::operator*(const Fixed& other) const
{
	Fixed result;
	long temp;
	
	temp = (long)this->value * (long)other.value;
	result.setRawBits((int)(temp >> this->bits));
	return result;
}

Fixed Fixed::operator/(const Fixed& other) const
{
	Fixed result;
	long temp;
	
	temp = ((long)this->value << this->bits) / other.value;
	result.setRawBits((int)temp);
	return result;
}

Fixed& Fixed::operator++()
{
	this->value++;
	return *this;
}

Fixed Fixed::operator++(int)
{
	Fixed temp = *this;
	this->value++;
	return temp;
}

Fixed& Fixed::operator--()
{
	this->value--;
	return *this;
}

Fixed Fixed::operator--(int)
{
	Fixed temp = *this;
	this->value--;
	return temp;
}

Fixed& Fixed::min(Fixed& a, Fixed& b)
{
	if (a < b)
		return a;
	return b;
}

const Fixed& Fixed::min(const Fixed& a, const Fixed& b)
{
	if (a < b)
		return a;
	return b;
}

Fixed& Fixed::max(Fixed& a, Fixed& b)
{
	if (a > b)
		return a;
	return b;
}

const Fixed& Fixed::max(const Fixed& a, const Fixed& b)
{
	if (a > b)
		return a;
	return b;
}

std::ostream& operator<<(std::ostream& out, const Fixed& fixed)
{
	out << fixed.toFloat();
	return out;
}

