/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdanish <mdanish@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 20:02:07 by mdanish           #+#    #+#             */
/*   Updated: 2025/01/25 23:28:04 by mdanish          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Span.hpp"
#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <unistd.h>

int rando(void) {
	static unsigned int i = 0;

	if (!(i % 4))
		return std::srand(time(0) + ++i), std::rand() / 123090;
	if (i % 4 == 1)
		return std::srand(time(0) - ++i), std::rand() / 123290;
	if (i % 4 == 2)
		return std::srand(time(0) * ++i), std::rand() / 123090;
	return std::srand(time(0) / ++i), std::rand() / 123090;
}

int main(void) {
	try {
		std::cout << "* Test 1 *\n";
		Span sp = Span(5);

		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);
		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;
		sp.addNumber(89);

	} catch (std::exception & error) {
		std::cerr << error.what() << '\n';
	}

	try {
		std::cout << "\n* Test 2 *\n";
		Span sp2 = Span(5);

		sp2.addNumber(6);
		std::cout << sp2.longestSpan() << std::endl;

	} catch (std::exception & error) {
		std::cerr << error.what() << '\n';
	}

	try {
		std::cout << "\n* Test 3 *\n";
		Span sp3(390350);
		std::vector<int> numbers(390350);

		std::generate(numbers.begin(), numbers.end(), rando);
		sp3.addMultipleNumbers(numbers.begin(), numbers.end());
		std::cout << sp3.shortestSpan() << std::endl;
		std::cout << sp3.longestSpan() << std::endl;

	} catch (std::exception & error) {
		std::cerr << error.what() << '\n';
	}

	return 0;
}