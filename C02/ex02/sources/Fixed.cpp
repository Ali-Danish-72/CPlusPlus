/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdanish <mdanish@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 17:29:34 by mdanish           #+#    #+#             */
/*   Updated: 2024/12/08 19:06:18 by mdanish          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Fixed.hpp"
#include <cmath>

Fixed::Fixed(void) {
	// std::cout << "Default constructor called\n";
	this->setRawBits(0);
	return;
}

Fixed::Fixed(int const wholeNumber) {
	// std::cout << "Int constructor called\n";
	this->setRawBits(wholeNumber << this->_fractionalBits);
	return;
}

Fixed::Fixed(float const decimalNumber) {
	// std::cout << "Float constructor called\n";
	this->setRawBits(roundf(decimalNumber * (1 << this->_fractionalBits)));
	return;
}

Fixed::Fixed(const Fixed & other) {
	// std::cout << "Copy constructor called\n";
	*this = other;
	return;
}

Fixed::~Fixed(void) {
	// std::cout << "Destructor called\n";
	return;
}

Fixed & Fixed::operator = (const Fixed & other) {
	// std::cout << "Copy assignment operator called\n";
	this->setRawBits(other.getRawBits());
	return *this;
}

bool Fixed::operator > (const Fixed & other) const {
	return this->getRawBits() > other.getRawBits();
}

bool Fixed::operator < (const Fixed & other) const {
	return this->getRawBits() < other.getRawBits();
}

bool Fixed::operator >= (const Fixed & other) const {
	return this->getRawBits() >= other.getRawBits();
}

bool Fixed::operator <= (const Fixed & other) const {
	return this->getRawBits() <= other.getRawBits();
}

bool Fixed::operator == (const Fixed & other) const {
	return this->getRawBits() == other.getRawBits();
}

bool Fixed::operator != (const Fixed & other) const {
	return this->getRawBits() != other.getRawBits();
}

Fixed Fixed::operator + (const Fixed & other) const {
	Fixed result(this->toFloat() + other.toFloat());
	return result;
}

Fixed Fixed::operator - (const Fixed & other) const {
	Fixed result(this->toFloat() - other.toFloat());
	return result;
}

Fixed Fixed::operator * (const Fixed & other) const {
	Fixed result(this->toFloat() * other.toFloat());
	return result;
}

Fixed Fixed::operator / (const Fixed & other) const {
	Fixed result(this->toFloat() / other.toFloat());
	return result;
}

Fixed Fixed::operator ++ (int) {
	Fixed store = *this;
	this->_value++;
	return store;
}

Fixed Fixed::operator -- (int) {
	Fixed store = *this;
	this->_value--;
	return store;
}

Fixed & Fixed::operator ++ (void) {
	this->_value++;
	return *this;
}

Fixed & Fixed::operator -- (void) {
	this->_value--;
	return *this;
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

Fixed & Fixed::min(Fixed & leftNumber, Fixed & rightNumber) {
	return leftNumber < rightNumber ? leftNumber : rightNumber;
}

const Fixed & Fixed::min(Fixed const & leftNumber, Fixed const & rightNumber) {
	return leftNumber < rightNumber ? leftNumber : rightNumber;
}

Fixed & Fixed::max(Fixed & leftNumber, Fixed & rightNumber) {
	return leftNumber > rightNumber ? leftNumber : rightNumber;
}

const Fixed & Fixed::max(Fixed const & leftNumber, Fixed const & rightNumber) {
	return leftNumber > rightNumber ? leftNumber : rightNumber;
}

std::ostream & operator << (std::ostream & out, const Fixed & other) {
	out << other.toFloat();
	return out;
}
