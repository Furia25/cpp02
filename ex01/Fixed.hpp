/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdurand <vdurand@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/15 14:31:47 by vdurand           #+#    #+#             */
/*   Updated: 2025/11/17 18:48:55 by vdurand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# define DEFAULT_MASK	8

# include <iostream>
# include <cmath>

class Fixed
{
public:
	Fixed();
	Fixed(const Fixed &other);
	Fixed(const int value);
	Fixed(const float value);
	~Fixed();
	/* methods */
	int				getRawBits(void) const;
	void			setRawBits(int const raw);
	float			toFloat(void) const;
	int				toInt(void) const;
	/*Operators overload*/
	Fixed			&operator=(const Fixed &other);
private:
	/* data */
	static const int	_mask = DEFAULT_MASK;
	int					_value;
};

std::ostream&	operator<<(std::ostream& os, const Fixed& obj);

#endif // FIXED_HPP