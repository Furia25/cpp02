/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdurand <vdurand@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 16:26:38 by vdurand           #+#    #+#             */
/*   Updated: 2025/12/17 16:04:13 by vdurand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point::Point() : _x(0), _y(0) {};

Point::Point(const float x, const float y) : _x(x), _y(y) {}
Point::Point(const Fixed x, Fixed y) : _x(x), _y(y) {}

Point::Point(const Point& other) : _x(other._x), _y(other._y) {}

Point::~Point() {}

Point&	Point::operator=(const Point& other)
{
	(void)other;
	return (*this);
}

const Fixed&	Point::getX(void) const
{
	return (_x);
}

const Fixed&	Point::getY(void) const
{
	return (_y);
}

Point	Point::operator+ (const Point& other)
{
	return (Point(this->getX() + other.getX(), this->getY() + other.getY()));
}

Point	Point::operator- (const Point& other)
{
	return (Point(this->getX() - other.getX(), this->getY() - other.getY()));
}

Point	Point::operator* (const Point& other)
{
	return (Point(this->getX() * other.getX(), this->getY() * other.getY()));
}

Point	Point::operator/ (const Point& other)
{
	return (Point(this->getX() / other.getX(), this->getY() / other.getY()));
}
