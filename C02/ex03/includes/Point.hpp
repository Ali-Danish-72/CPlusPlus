/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdanish <mdanish@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 17:37:59 by mdanish           #+#    #+#             */
/*   Updated: 2024/12/08 20:22:24 by mdanish          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Fixed.hpp"

class Point {
	private:
		const Fixed _x;
		const Fixed _y;
	
	public:
		Point(void);
		Point(const float x, const float y);
		Point(float x);
		Point(Point const & other);
		~Point(void);

		Point & operator = (Point & other);

		Fixed const & getX(void) const;
		Fixed const & getY(void) const;
};

bool bsp(Point const a, Point const b, Point const c, Point const point);
