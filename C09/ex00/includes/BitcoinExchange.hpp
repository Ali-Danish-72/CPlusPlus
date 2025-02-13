/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdanish <mdanish@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 19:29:53 by mdanish           #+#    #+#             */
/*   Updated: 2025/02/13 18:34:56 by mdanish          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <stdexcept>
#include <algorithm>
#include <cctype>
#include <cstdlib>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <map>
#include <string>
#include <utility>

class BitcoinExchange {
	private:
		std::map<std::string, float> _exchangeDatabase;

	public:
		BitcoinExchange(void);
		BitcoinExchange(const BitcoinExchange & other);
		~BitcoinExchange(void);
		BitcoinExchange & operator = (const BitcoinExchange & other);

		std::pair<std::string, float> parseLine(std::string line) throw(std::runtime_error);
		void printValue(std::pair<std::string, float> dateValuePair) throw(std::runtime_error);
};
