/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdanish <mdanish@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 18:04:39 by mdanish           #+#    #+#             */
/*   Updated: 2024/12/08 20:22:45 by mdanish          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Point.hpp"

Point::Point(void) : _x(0), _y(0) {
	return ;
}

Point::Point(const float x) : _x(x), _y(5) {
	return ;
}

Point::Point(const float x, const float y) : _x(x), _y(y) {
	return ;
}

Point::Point(Point const & other) : _x(other._x), _y(other._y) {
	return ;
}

Point::~Point(void) {
	return ;
}

Point & Point::operator = (Point & other) {
	(void)other;
	return *this;
}

Fixed const & Point::getX(void) const {
	return this->_x;
}

Fixed const & Point::getY(void) const {
	return this->_y;
}
