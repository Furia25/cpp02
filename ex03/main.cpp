/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdurand <vdurand@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 17:21:23 by vdurand           #+#    #+#             */
/*   Updated: 2025/11/18 17:29:46 by vdurand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Fixed.hpp"
#include "Point.hpp"

void	test(const char *name, const Point &P, const Point &A, const Point &B, const Point &C)
{
	std::cout << name
	          << " -> "
	          << (bsp(A, B, C, P) ? "true" : "false")
	          << std::endl;
}

int	main()
{
	Point A(0.0f, 0.0f);
	Point B(5.0f, 0.0f);
	Point C(2.5f, 5.0f);

	Point P_inside(2.5f, 2.0f);
	Point P_outside(5.0f, 5.0f);
	Point P_edge(2.5f, 0.0f);
	Point P_vertex(0.0f, 0.0f);

	std::cout << "Triangle : A(0,0), B(5,0), C(2.5,5)" << std::endl;

	test("Inside ", P_inside, A, B, C);
	test("Outside", P_outside, A, B, C);
	test("Edge   ", P_edge, A, B, C);
	test("Vertex ", P_vertex, A, B, C);

	return 0;
}
