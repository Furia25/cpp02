/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdurand <vdurand@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 16:26:36 by vdurand           #+#    #+#             */
/*   Updated: 2025/12/17 16:16:01 by vdurand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

static inline float	signed_area(Point p1, Point p2, Point p3)
{
	return ((
		(p1.getX() - p3.getX()) * 
		(p2.getY() - p3.getY()) - 
		(p2.getX() - p3.getX()) * 
		(p1.getY() - p3.getY())).toFloat());
}

bool	bsp(const Point a, const Point b, const Point c, const Point point)
{
	float d1 = signed_area(point, a, b);
	float d2 = signed_area(point, b, c);
	float d3 = signed_area(point, c, a);

	//Check for bad triangles
	if (d1 + d2 + d3 == 0.0f)
		return (false);

	bool has_neg = (d1 < 0.0f) || (d2 < 0.0f) || (d3 < 0.0f);
	bool has_pos = (d1 > 0.0f) || (d2 > 0.0f) || (d3 > 0.0f);

	if (d1 == 0 || d2 == 0 || d3 == 0)
		return (false);
	return (!(has_neg && has_pos));
}
