#ifndef POINT_HPP
# define POINT_HPP

# include "Fixed.hpp"

class Point
{
public:
	Point();
	Point(const float x, const float y);
	Point(const Fixed x, Fixed y);
	Point(const Point &);
	~Point();

	const Fixed&	getX(void) const;
	const Fixed&	getY(void) const;

	/*Operators overload*/
	Point&		operator= (const Point& other);
private:
	const Fixed	_x;
	const Fixed	_y;
	Point		operator+ (const Point& other);
	Point		operator- (const Point& other);
	Point		operator* (const Point& other);
	Point		operator/ (const Point& other);
};

#endif // POINT_HPP