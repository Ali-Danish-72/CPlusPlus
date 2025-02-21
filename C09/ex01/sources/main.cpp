/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdanish <mdanish@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 13:38:12 by mdanish           #+#    #+#             */
/*   Updated: 2025/02/21 16:37:44 by mdanish          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/RPN.hpp"

int main(int ac, char **av) {
	if (ac != 2) {
		std::cerr << "Use the program as follows:\n./RPN [string of numbers and operands].\n";
		return 1;
	}

	RPN calculator;
	try {
		calculator.parseInput(av[1]);
		calculator.printResult();
	} catch (std::exception & error) {
		std::cerr << "Error: " << error.what() << '\n';
		return 2;
	}
	return 0;
}
