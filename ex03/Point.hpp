/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdurand <vdurand@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/16 17:15:47 by vdurand           #+#    #+#             */
/*   Updated: 2025/12/17 16:04:16 by vdurand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP
# define POINT_HPP

# include "Fixed.hpp"

class Point
{
public:
	Point();
	Point(const float x, const float y);
	Point(const Fixed x, Fixed y);
	Point(const Point& other);
	~Point();

	const Fixed&	getX(void) const;
	const Fixed&	getY(void) const;

	/*Operators overload*/
	Point&		operator= (const Point& other);
	Point		operator+ (const Point& other);
	Point		operator- (const Point& other);
	Point		operator* (const Point& other);
	Point		operator/ (const Point& other);
private:
	const Fixed	_x;
	const Fixed	_y;
};

bool	bsp(const Point a, const Point b, const Point c, const Point point);

#endif // POINT_HPP
