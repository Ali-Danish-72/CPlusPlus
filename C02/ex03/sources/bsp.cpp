/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdanish <mdanish@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 18:22:38 by mdanish           #+#    #+#             */
/*   Updated: 2024/12/08 20:59:12 by mdanish          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Point.hpp"
#include <cmath>

bool bsp(const Point a, const Point b, const Point c, const Point point) {
	Fixed totalArea(std::fabs(((a.getX() * (b.getY() - c.getY()) + b.getX() * 
	(c.getY() - a.getY()) + c.getX() * (a.getY() - b.getY())) / Fixed(2)).toFloat()));

	Fixed pabArea(std::fabs(((a.getX() * (b.getY() - point.getY()) + b.getX() * 
	(point.getY() - a.getY()) + point.getX() * (a.getY() - b.getY())) / Fixed(2)).toFloat()));

	Fixed pacArea(std::fabs(((a.getX() * (point.getY() - c.getY()) + point.getX() * 
	(c.getY() - a.getY()) + c.getX() * (a.getY() - point.getY())) / Fixed(2)).toFloat()));

	Fixed pbcArea(std::fabs(((point.getX() * (b.getY() - c.getY()) + b.getX() * 
	(c.getY() - point.getY()) + c.getX() * (point.getY() - b.getY())) / Fixed(2)).toFloat()));

	if (!totalArea || !pabArea || !pacArea || !pbcArea)
		return false;
	return totalArea == (pabArea + pacArea + pbcArea);
}
