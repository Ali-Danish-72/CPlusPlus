/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdanish <mdanish@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 17:16:01 by mdanish           #+#    #+#             */
/*   Updated: 2024/12/08 19:29:46 by mdanish          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>

class Fixed {
	private:
		int _value;
		static const int _fractionalBits = 8;

	public:
		Fixed(void);
		Fixed(int const wholeNumber);
		Fixed(float const decimalNumber);
		Fixed(const Fixed & other);
		~Fixed(void);

		Fixed & operator = (const Fixed & other);
		bool operator > (const Fixed & other) const;
		bool operator < (const Fixed & other) const;
		bool operator >= (const Fixed & other) const;
		bool operator <= (const Fixed & other) const;
		bool operator == (const Fixed & other) const;
		bool operator != (const Fixed & other) const;
		bool operator ! (void) const;
		Fixed operator + (const Fixed & other) const;
		Fixed operator - (const Fixed & other) const;
		Fixed operator * (const Fixed & other) const;
		Fixed operator / (const Fixed & other) const;
		Fixed operator ++ (int);
		Fixed operator -- (int);
		Fixed & operator ++ (void);
		Fixed & operator -- (void);

		float toFloat(void) const;
		int toInt(void) const;
		int getRawBits(void) const;
		void setRawBits(int const rawBits);
		static Fixed & min(Fixed & leftNumber, Fixed & rightNumber);
		static const Fixed & min(Fixed const &leftNumber, Fixed const &rightNumber);
		static Fixed & max(Fixed & leftNumber, Fixed & rightNumber);
		static const Fixed & max(Fixed const & leftNumber, Fixed const & rightNumber);
};

std::ostream & operator << (std::ostream & out, const Fixed & other);
