/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdanish <mdanish@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 16:53:25 by mdanish           #+#    #+#             */
/*   Updated: 2025/01/24 20:28:15 by mdanish          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Span.hpp"
#include <algorithm>
#include <limits>

Span::Span(unsigned int numberOfIntegers) {
	this->_integerCount = numberOfIntegers;
}

Span::Span(const Span & other) : _integers(other._integers) {
	this->_integerCount = other._integerCount;
}

Span::~Span() {}

Span & Span::operator = (const Span & other) {
	if (this != &other) {
		this->_integerCount = other._integerCount;
		this->_integers = other._integers;
	}
	return *this;
}

const char * Span::ExcessiveAddition::what() const throw() {
	return "Attempted to add a number when the allocated size is exhausted.";
}

const char * Span::SpanCalculationIsNotPossible::what() const throw() {
	return "Insufficient numbers are available for calculations.";
}

void Span::addNumber(int numberToAdd) {
	this->_integers.size() == this->_integerCount ? throw ExcessiveAddition() :
	this->_integers.insert(this->_integers.begin(), numberToAdd);
}

int Span::shortestSpan(void) {
	if (this->_integers.size() < 2) throw SpanCalculationIsNotPossible();

	std::sort(this->_integers.begin(), this->_integers.end());
	int shortestSpan = std::numeric_limits<int>::max();
	std::vector<int>::const_iterator end = this->_integers.end();
	for (std::vector<int>::const_iterator iter = this->_integers.begin() + 1; iter != end; iter++) {
		if (*iter - *(iter - 1) < shortestSpan)
			shortestSpan = *iter - *(iter - 1);
	}
	return shortestSpan;
}

int Span::longestSpan(void) {
	if (this->_integers.size() < 2) throw SpanCalculationIsNotPossible();

	std::sort(this->_integers.begin(), this->_integers.end());
	return this->_integers.back() - this->_integers.front();
}

static void printer(int toPrint) {
	std::cout << toPrint << ' ';
}

void Span::printNumbers(void) {
	std::sort(this->_integers.begin(), this->_integers.end());
	std::for_each(this->_integers.begin(), this->_integers.end(), printer);
	std::cout << std::endl;
}
