/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdanish <mdanish@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 17:29:34 by mdanish           #+#    #+#             */
/*   Updated: 2024/12/06 19:17:12 by mdanish          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Fixed.hpp"
#include <iostream>

Fixed::Fixed() : _value(0) {
	std::cout << "Default constructor called\n";
	return;
}

Fixed::Fixed(const Fixed &other) {
	std::cout << "Copy constructor called\n";
	this->setRawBits(other.getRawBits());
	return;
}

Fixed &Fixed::operator=(const Fixed &other) {
	std::cout << "Copy assignment operator called\n";
	this->setRawBits(other.getRawBits());
	return *this;
}

Fixed::~Fixed() {
	std::cout << "Destructor called\n";
	return;
}

int Fixed::getRawBits(void) const {
	std::cout << "getRawBits member function called\n";
	return this->_value;
}

void Fixed::setRawBits(int const rawBits) {
	std::cout << "setRawBits member function called\n";
	this->_value = rawBits;
}
