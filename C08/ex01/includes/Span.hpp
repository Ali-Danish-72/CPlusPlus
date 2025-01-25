/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdanish <mdanish@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 16:34:05 by mdanish           #+#    #+#             */
/*   Updated: 2025/01/24 19:55:45 by mdanish          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <exception>
#include <vector>
#include <iostream>

class Span {
	private:
		std::vector<int> _integers;
		unsigned int _integerCount;

		Span();

	public:
		Span(unsigned int numberOfIntegers);
		Span(const Span & other);
		~Span();
		Span & operator = (const Span & other);

		class ExcessiveAddition : public std::exception {
			const char * what() const throw();
		};
		class SpanCalculationIsNotPossible : public std::exception {
			const char * what() const throw();
		};

		int shortestSpan(void);
		int longestSpan(void);

		void addNumber(int numberToAdd);
		template <class Iterator> void addMultipleNumbers(Iterator start, Iterator finish) {
			if (std::distance(start, finish) + this->_integers.size() > this->_integerCount)
				throw ExcessiveAddition();
			this->_integers.insert(this->_integers.end(), start, finish);
		}

		void printNumbers(void);
};

std::ostream & operator << (std::ostream & out, const Span & other);
