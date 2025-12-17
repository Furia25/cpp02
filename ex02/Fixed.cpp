/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdurand <vdurand@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 16:26:42 by vdurand           #+#    #+#             */
/*   Updated: 2025/12/17 15:59:39 by vdurand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

const int Fixed::_mask = FIXED_DEFAULT_MASK;

Fixed::Fixed() : _value(0)
{
	#if DEBUG_MESSAGE == true
		std::cout << "Default constructor called" << std::endl;
	#endif
};

Fixed::Fixed(const int value)
{
	#if DEBUG_MESSAGE == true
		std::cout << "Int constructor called" << std::endl;
	#endif
	this->_value = value << this->_mask;
}

Fixed::Fixed(const float value)
{
	#if DEBUG_MESSAGE == true
		std::cout << "Float constructor called" << std::endl;
	#endif
	this->_value = static_cast<int>(roundf(value * (1 << this->_mask)));
}

Fixed::Fixed(const Fixed& other)
{
	#if DEBUG_MESSAGE == true
		std::cout << "Copy constructor called" << std::endl;
	#endif
	*this = other;
};

Fixed::~Fixed()
{
	#if DEBUG_MESSAGE == true
		std::cout << "Destructor called" << std::endl;
	#endif
}

Fixed	&Fixed::operator=(const Fixed& other)
{
	#if DEBUG_MESSAGE == true
		std::cout << "Copy assignment operator called" << std::endl;
	#endif
	this->_value = other._value;	
	return (*this);
}

Fixed& Fixed::operator+=(const Fixed& other)
{
	this->_value += other._value;
	return (*this);
}

Fixed& Fixed::operator-=(const Fixed& other)
{
	this->_value -= other._value;
	return (*this);
}

Fixed& Fixed::operator*=(const Fixed& other)
{
	this->_value *= other.toFloat();
	return (*this);
}

Fixed& Fixed::operator/=(const Fixed& other)
{
	this->_value /= other.toFloat();
	return (*this);
}

Fixed& Fixed::operator++()
{
	++_value;
	return (*this);
}

Fixed& Fixed::operator--()
{
	--_value;
	return (*this);
}

Fixed	Fixed::operator++(int)
{
	Fixed	temp(*this);
	++(*this);
	return (temp);
}

Fixed	Fixed::operator--(int)
{
	Fixed	temp(*this);
	--(*this);
	return (temp);
}

Fixed&	Fixed::min(Fixed& l, Fixed& r)
{
	if (l > r)
		return (r);
	return (l);
}

const Fixed&	Fixed::min(const Fixed& l, const Fixed& r)
{
	if (l > r)
		return (r);
	return (l);
}

Fixed&	Fixed::max(Fixed& l, Fixed& r)
{
	if (l >= r)
		return (l);
	return (r);
}

const Fixed&	Fixed::max(const Fixed& l, const Fixed& r)
{
	if (l >= r)
		return (l);
	return (r);
}

int	Fixed::getRawBits(void) const
{
	#if DEBUG_MESSAGE == true
		std::cout << "getRawBits member function called" << std::endl;
	#endif
	return (this->_value);
}

void	Fixed::setRawBits(int const raw)
{
	#if DEBUG_MESSAGE == true
		std::cout << "setRawBits member function called" << std::endl;
	#endif
	this->_value = raw;
}

float Fixed::toFloat(void) const
{
	return (this->_value / static_cast<float>(1 << this->_mask));
}

int Fixed::toInt(void) const
{
	return (this->_value >> this->_mask);
}

/* ---------- Non Member ---------- */

std::ostream&	operator<<(std::ostream& os, const Fixed& obj)
{
	os << obj.toFloat();
	return (os);
}

bool operator<(const Fixed& l, const Fixed& r)
{
	return (l.getRawBits() < r.getRawBits());
}

bool operator>(const Fixed& l, const Fixed& r)
{
	return (r < l);
}

bool operator<=(const Fixed& l, const Fixed& r)
{
	return (!(l > r));
}

bool operator>=(const Fixed& l, const Fixed& r)
{
	return (!(l < r));
}

bool operator==(const Fixed& l, const Fixed& r)
{
	return (l.getRawBits() == r.getRawBits());
}

bool operator!=(const Fixed& l, const Fixed& r)
{
	return (!(l == r));
}

Fixed	operator+(const Fixed& l, const Fixed& r)
{
	Fixed	result = l;
	result += r;
	return (result);
}

Fixed	operator-(const Fixed& l, const Fixed& r)
{
	Fixed	result = l;
	result -= r;
	return (result);
}

Fixed	operator*(const Fixed& l, const Fixed& r)
{
	Fixed	result = l;
	result *= r;
	return (result);
}

Fixed	operator/(const Fixed& l, const Fixed& r)
{
	Fixed	result = l;
	result /= r;
	return (result);
}
