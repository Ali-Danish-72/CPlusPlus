/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdanish <mdanish@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 22:14:05 by mdanish           #+#    #+#             */
/*   Updated: 2025/01/14 10:41:16 by mdanish          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Array.hpp"
#include <iostream>

int main() {
	std::cout << "* TESTING FOR INVALID ACCESS *\n";
	try {
		Array<std::string> strings;
		std::cout << strings[0];
	} catch (std::exception & error) {
		std::cerr << error.what() << '\n';
	}
	try {
		Array<char> chars(3);
		std::cout << chars[6];
	} catch (std::exception & error) {
		std::cerr << error.what() << '\n';
	}

	std::cout << "\n* TESTING FOR READ AND WRITE OPERATIONS *\n";
	try {
		Array<std::string> strings(5);
		strings[0] = "Zeroth string";
		strings[1] = "First string";
		strings[2] = "Second string";
		strings[3] = "Third string";
		strings[4] = "Fourth string";

		std::cout << strings[0] << '\n';
	} catch (std::exception & error) {
		std::cerr << error.what() << '\n';
	}
	try {
		Array<int> ints(10);
		for (int i = 0; i < 10; ++i)
			ints[i] = i;
		std::cout << ints[6];
	} catch (std::exception & error) {
		std::cerr << error.what() << '\n';
	}

	std::cout << "\n* TESTING FOR DEEP COPY IN COPY CONSTRUCTOR *\n";
	try {
		Array<float> floats1(3);
		floats1[0] = 1.5;
		floats1[1] = 3.0;
		floats1[2] = 4.5;
		Array<float> floats2(floats1);
		std::cout << "Before the change:\n<" << floats1[0] << "> <" << floats1[1] << "> <" << floats1[2] << ">\n<" << floats2[0] << "> <" << floats2[1] << "> <" << floats2[2] << ">\n";
		floats2[0] = 6.0;
		floats2[1] = 7.5;
		floats2[2] = 9.0;
		std::cout << "After the change:\n<" << floats1[0] << "> <" << floats1[1] << "> <" << floats1[2] << ">\n<" << floats2[0] << "> <" << floats2[1] << "> <" << floats2[2] << ">\n";
	} catch(std::exception & error) {
		std::cerr << error.what() << '\n';
	}

	std::cout << "\n* TESTING FOR DEEP COPY IN COPY ASSIGNMENT OPERATOR *\n";
	try {
		Array<double> doubles1(3);
		doubles1[0] = 1.5;
		doubles1[1] = 3.0;
		doubles1[2] = 4.5;
		Array<double> doubles2(1);
		doubles2[0] = 23.41;
		std::cout << "Before assignment:\n<" << doubles1[0] << "> <" << doubles1[1] << "> <" << doubles1[2] << ">\n<" << doubles2[0] << ">\n";
		doubles2 = doubles1;
		std::cout << "After the assignment, before the change:\n<" << doubles1[0] << "> <" << doubles1[1] << "> <" << doubles1[2] << "\n<" << doubles2[0] << "> <" << doubles2[1] << "> <" << doubles2[2] << ">\n";
		doubles2[0] = 6.0;
		doubles2[1] = 7.5;
		doubles2[2] = 9.0;
		std::cout << "After the change:\n<" << doubles1[0] << "> <" << doubles1[1] << "> <" << doubles1[2] << "\n<" << doubles2[0] << "> <" << doubles2[1] << "> <" << doubles2[2] << ">\n";
	} catch(std::exception & error) {
		std::cerr << error.what() << '\n';
	}
}
