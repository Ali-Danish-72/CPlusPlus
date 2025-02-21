/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdanish <mdanish@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 19:35:53 by mdanish           #+#    #+#             */
/*   Updated: 2025/02/21 16:54:05 by mdanish          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <sstream>
#include <stack>

class RPN {
	private:
		std::stack<int> _mainStack;

		void operationTime(char operatorCase) throw(std::runtime_error);

	public:
		RPN(void);
		RPN(const RPN & other);
		~RPN(void);
		RPN & operator = (const RPN & other);

		void parseInput(std::string inputString) throw(std::runtime_error);
		void printResult(void) throw(std::runtime_error);
};
