/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdanish <mdanish@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 19:35:53 by mdanish           #+#    #+#             */
/*   Updated: 2025/02/22 17:13:04 by mdanish          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <stdexcept>
#include <sstream>
#include <stack>

class RPN {
	private:
		std::stack<int> _mainStack;

		RPN(const RPN & other);
		RPN & operator = (const RPN & other);

		void operationTime(char operatorCase) throw(std::runtime_error);

	public:
		RPN(void);
		~RPN(void);

		void parseInput(std::string inputString) throw(std::runtime_error);
		void printResult(void) throw(std::runtime_error);
};
