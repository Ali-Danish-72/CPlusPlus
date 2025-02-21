/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdanish <mdanish@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 20:06:55 by mdanish           #+#    #+#             */
/*   Updated: 2025/02/21 16:52:51 by mdanish          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/RPN.hpp"

RPN::RPN() {}

RPN::RPN(const RPN & other) { *this = other; }

RPN::~RPN() {}

RPN & RPN::operator = (const RPN & other) {
	if (this != &other)
		this->_mainStack = other._mainStack;
	return *this;
}

void RPN::operationTime(char operatorCharacter) throw(std::runtime_error) {
	int topNumber = this->_mainStack.top();

	if (operatorCharacter == '/' && !topNumber)
		throw (std::runtime_error("Attempting division by zero."));
	this->_mainStack.pop();
	switch (std::string("+-*/").find(operatorCharacter)) {
		case 0:
			this->_mainStack.top() = this->_mainStack.top() + topNumber;
			return;
		case 1:
			this->_mainStack.top() = this->_mainStack.top() - topNumber;
			return;
		case 2:
			this->_mainStack.top() = this->_mainStack.top() * topNumber;
			return;
		case 3:
			this->_mainStack.top() = this->_mainStack.top() / topNumber;
	}
}

void RPN::parseInput(std::string inputString) throw(std::runtime_error) {
	while (!this->_mainStack.empty())
		this->_mainStack.pop();
	std::istringstream input(inputString);
	std::string extractedOperator;
	int extractedNumber;
	input >> extractedOperator;
	do {
		if (input.fail())
			throw std::runtime_error("Error encountered while parsing the prompt.");
		if (extractedOperator.size() == 1 && extractedOperator.find_first_of("*/-+") != std::string::npos)
			this->_mainStack.size() < 2 ? throw std::runtime_error("Insufficient operands.") : operationTime(extractedOperator[0]);
		else {
			std::istringstream store(extractedOperator);
			if ((store >> extractedNumber).fail() || !store.eof())
				throw std::runtime_error("Unexpected token.");
			this->_mainStack.push(extractedNumber);
		}
		extractedOperator = "";
		input >> extractedOperator;
	} while (!input.eof());
	if (extractedOperator != "") {
		if (extractedOperator.size() == 1 && extractedOperator.find_first_of("*/-+") != std::string::npos)
			this->_mainStack.size() < 2 ? throw std::runtime_error("Insufficient operands.") : operationTime(extractedOperator[0]);
		else {
			std::istringstream store(extractedOperator);
			if ((store >> extractedNumber).fail() || !store.eof())
				throw std::runtime_error("Unexpected token.");
			this->_mainStack.push(extractedNumber);
		}
	}
}

void RPN::printResult() throw(std::runtime_error) {
	this->_mainStack.size() == 1 ? std::cout << this->_mainStack.top() << '\n' : std::cerr << "Error: Not all operands are used.\n";
}
