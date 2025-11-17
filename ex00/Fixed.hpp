/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdurand <vdurand@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/15 14:31:47 by vdurand           #+#    #+#             */
/*   Updated: 2025/11/17 19:19:31 by vdurand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# define DEFAULT_MASK	8

# include <iostream>

class Fixed
{
public:
	Fixed();
	Fixed(const Fixed& other);
	Fixed(const int n);
	Fixed(const float n);
	Fixed&	operator=(const Fixed& other);
	~Fixed();
	/* methods */
	int		getRawBits(void) const;
	void	setRawBits(int const raw);
private:
	/* data */
	static const int	_mask = DEFAULT_MASK;
	int					_value;
};

#endif // FIXED_HPP