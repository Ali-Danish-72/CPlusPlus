/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdanish <mdanish@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 15:42:08 by mdanish           #+#    #+#             */
/*   Updated: 2025/02/13 19:34:04 by mdanish          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/BitcoinExchange.hpp"

int main(int ac, char **av) {
	if (ac != 2) {
		std::cerr << "Use the program as follows:\n./btc [file name]\n";
		return 1;
	}

	try {
		BitcoinExchange exchanger;
		std::ifstream inputFile(av[1]);
		if (!inputFile.is_open())
			throw std::invalid_argument("Error in opening the input file.");
		std::cout.setf(std::ios_base::fixed, std::ios_base::floatfield);
		try {
			std::string retrievedEntry;
			std::getline(inputFile, retrievedEntry);
			if (inputFile.fail())
				throw std::invalid_argument("Error in reading the input file.");
			if (retrievedEntry != "date | value")
				throw std::invalid_argument("Invalid formatting of the input file.");
			std::getline(inputFile, retrievedEntry);
			do {
				if (inputFile.fail())
					throw std::invalid_argument("Error in reading the input file.");
				try { exchanger.printValue(exchanger.parseLine(retrievedEntry)); }
				catch (std::runtime_error & error) { std::cout << "Error: " << error.what() << '\n'; }
				std::getline(inputFile, retrievedEntry);
			} while (!inputFile.eof());
			if (retrievedEntry != "") {
				if (inputFile.fail())
					throw std::invalid_argument("Error in reading the input file.");
				try { exchanger.printValue(exchanger.parseLine(retrievedEntry)); }
				catch (std::runtime_error & error) { std::cout << "Error: " << error.what() << '\n'; }
			}
		} catch (std::exception & error) {
			inputFile.close();
			throw;
		}
		inputFile.close();
	} catch (std::exception & error) {
		std::cerr << error.what() << '\n';
	}
	return 0;
}
