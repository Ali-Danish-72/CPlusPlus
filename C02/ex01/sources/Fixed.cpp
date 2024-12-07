/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdanish <mdanish@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 17:29:34 by mdanish           #+#    #+#             */
/*   Updated: 2024/12/07 17:44:14 by mdanish          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Fixed.hpp"
#include <cmath>

Fixed::Fixed(void) {
	std::cout << "Default constructor called\n";
	this->setRawBits(0);
	return;
}

Fixed::Fixed(int const wholeNumber) {
	std::cout << "Int constructor called\n";
	this->setRawBits(wholeNumber << this->_fractionalBits);
	return;
}

Fixed::Fixed(float const decimalNumber) {
	std::cout << "Float constructor called\n";
	this->setRawBits(roundf(decimalNumber * (1 << this->_fractionalBits)));
	return;
}

Fixed::Fixed(const Fixed &other) {
	std::cout << "Copy constructor called\n";
	*this = other;
	return;
}

Fixed &Fixed::operator=(const Fixed &other) {
	std::cout << "Copy assignment operator called\n";
	this->setRawBits(other.getRawBits());
	return *this;
}

Fixed::~Fixed(void) {
	std::cout << "Destructor called\n";
	return;
}

int Fixed::toInt(void) const {
	return getRawBits() >> this->_fractionalBits;
}

float Fixed::toFloat(void) const {
	return static_cast<float>(getRawBits()) / (1 << this->_fractionalBits);
}

int Fixed::getRawBits(void) const {
	return this->_value;
}

void Fixed::setRawBits(int const rawBits) {
	this->_value = rawBits;
}

std::ostream &operator<<(std::ostream &out, const Fixed &other) {
	out << other.toFloat();
	return out;
}
