/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Converter.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdanish <mdanish@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 23:11:43 by mdanish           #+#    #+#             */
/*   Updated: 2025/01/12 04:57:26 by mdanish          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Converter.hpp"

static void convertFromCharacter(char c) {
	if (!isprint(c))
		std::cout << "char: Not Displayable\nint: Impossible\nfloat: Impossible\ndouble: Impossible";
	else {
		int i = c;

		std::cout << "char: " << c << "\nint: " << i << '\n' << "float: " << i << ".0f\ndouble: " << i << ".0";
	}
	std::cout << '\n';
}

static void convertFromInteger(long long int i) {
	if (i < std::numeric_limits<int>::min())
		std::cout << "char: Impossible\nint: Number is smaller than the minimum integer representation.\nfloat: Impossible\ndouble: Impossible";
	else if (i > std::numeric_limits<int>::max())
		std::cout << "char: Impossible\nint: Number is greater than the maximum integer representation.\nfloat: Impossible\ndouble: Impossible";
	else {
		char c = i;
		double d = i;

		std::cout << "char: " << (i > 31 && i < 127 ? &c : "Not Displayable");

		std::cout << "\nint: " << i;

		std::cout << "\nfloat: " << d;
		if (d < 1000000 || d > -1000000)
			std::cout << ".0";

		std::cout << "f\ndouble: " << d;
		if (d < 1000000 || d > -1000000)
			std::cout << ".0";
	}
	std::cout << '\n';
}

static void convertFromFloat(std::string input) {
	if (input == "nanf") std::cout << "char: Impossible\nint: Impossible\nfloat: nanf\ndouble: nan";
	else if (input == "+inff") std::cout << "char: Impossible\nint: Impossible\nfloat: +inff\ndouble: +inf";
	else if (input == "-inff") std::cout << "char: Impossible\nint: Impossible\nfloat: -inff\ndouble: -inf";
	else {
		char * endPointer;
		double d = strtold(input.c_str(), &endPointer);
		if (d < std::numeric_limits<float>::max() * -1)
			std::cout << "char: Impossible\nint: Impossible\nfloat: Number is smaller than the minimum float representation.\ndouble: Impossible";
		else if (d > std::numeric_limits<float>::max())
			std::cout << "char: Impossible\nint: Impossible\nfloat: Number is greater than the maximum float representation.\ndouble: Impossible";
		else {
			char c = d;

			std::cout << "char: ";
			if (d > 31 && d < 127) std::cout << c;
			else std::cout << "Not Displayable";

			std::cout << "\nint: ";
			if (d < std::numeric_limits<int>::min()) std::cout << "Number is lower than the minimum integer representation.";
			else if (d > std::numeric_limits<int>::max()) std::cout << "Number is greater than the maximum integer representation.";
			else std::cout << static_cast<int>(d);

			d == floor(d) && (d > -1000000 || d < 1000000) ?  std::cout << "\nfloat: " << d << ".0f\ndouble: " << d << ".0" : std::cout << "\nfloat: " << d << "f\ndouble: " << d;
		}
	}
	std::cout << '\n';
}

static void convertFromDouble(std::string input) {
	if (input == "nan") std::cout << "char: Impossible\nint: Impossible\nfloat: nanf\ndouble: nan";
	else if (input == "+inf") std::cout << "char: Impossible\nint: Impossible\nfloat: +inff\ndouble: +inf";
	else if (input == "-inf") std::cout << "char: Impossible\nint: Impossible\nfloat: -inff\ndouble: -inf";
	else {
		char * endPointer;
		long double d = strtold(input.c_str(), &endPointer);
		if (d < std::numeric_limits<double>::max() * -1)
			std::cout << "char: Impossible\nint: Impossible\nfloat: Impossible\ndouble: Number is smaller than the minimum double representation.";
		else if (d > std::numeric_limits<double>::max())
			std::cout << "char: Impossible\nint: Impossible\nfloat: Impossible\ndouble: Number is greater than the maximum double representation.";
		else {
			char c = d;

			std::cout << "char: ";
			if (d > 31 && d < 127) std::cout << c;
			else std::cout << "Not Displayable";

			std::cout << "\nint: ";
			if (d < std::numeric_limits<int>::min()) std::cout << "Number is lower than the minimum integer representation.";
			else if (d > std::numeric_limits<int>::max()) std::cout << "Number is greater than the maximum integer representation.";
			else std::cout << static_cast<int>(d);

			std::cout << "\nfloat: ";
			if (d < (std::numeric_limits<float>::max() * -1)) std::cout << "Number is lower than the minimum float representation.";
			else if (d > std::numeric_limits<float>::max()) std::cout << "Number is greater than the maximum float representation.";
			else std::cout << d << (d == floor(d) && (d > -1000000 || d < 1000000) ? ".0f" : "f");

			std::cout << "\ndouble: " << d;
			if (d == floor(d) && (d > -1000000 || d < 1000000)) std::cout << ".0";
		}
	}
	std::cout << '\n';
}

void ScalarConverter::convert(std::string input) {
	if (!input[1] && !isdigit(input[0])) return convertFromCharacter(input[0]);

	char * endPointer;
	long long int value = strtoll(input.c_str(), &endPointer, 10);
	if (!*endPointer) return convertFromInteger(value);

	if (input.find(".") != std::string::npos || input == "nanf" || input == "+inff" || input == "-inf" || input == "nan" || input == "+inf" || input == "-inf")
		input.find('f') == std::string::npos || input == "+inf" || input == "-inf" ? convertFromDouble(input) : convertFromFloat(input);
}
