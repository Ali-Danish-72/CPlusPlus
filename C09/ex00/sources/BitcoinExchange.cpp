/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdanish <mdanish@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 19:38:14 by mdanish           #+#    #+#             */
/*   Updated: 2025/02/13 19:34:38 by mdanish          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange(void) {
	std::ifstream database("./sources/data.csv");
	try {
		if (!database.is_open())
			throw 0;
		std::string retrievedEntry;
		std::getline(database, retrievedEntry);
		std::getline(database, retrievedEntry);
		do {
			if (database.fail())
				throw 1;
			this->_exchangeDatabase[retrievedEntry.substr(0, retrievedEntry.find(','))] = std::atof(retrievedEntry.substr(retrievedEntry.find(',') + 1, std::string::npos).c_str());
			std::getline(database, retrievedEntry);
		} while (!database.eof());
	} catch (int errorCode) {
		if (errorCode)
			database.close();
		throw std::logic_error("The set up for the database failed.");
	}
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange & other) {
	*this = other;
}

BitcoinExchange::~BitcoinExchange(void) {}

BitcoinExchange & BitcoinExchange::operator = (const BitcoinExchange & other) {
	if (this != & other)
		this->_exchangeDatabase = other._exchangeDatabase;
	return *this;
}

static int precisionCount;

static inline bool isSpace(unsigned char c) { return std::isspace(c); }

static inline bool isDigit(unsigned char c) { return std::isdigit(c); }

std::pair<std::string, float> BitcoinExchange::parseLine(std::string line) throw(std::runtime_error) {

	if (std::count(line.begin(), line.end(), '|') != 1)
		throw std::runtime_error("bad input => " + line);

	std::string lineStore = line;
	line.erase(std::remove_if(line.begin(), line.end(), isSpace), line.end());
	std::string date = line.substr(0, line.find('|')), amount = line.substr(line.find('|') + 1, std::string::npos);
	int dotCount = std::count(amount.begin(), amount.end(), '.') + (amount[0] == '-');
	if (date.size() != 10 || std::count_if(date.begin(), date.end(), isDigit) != 8 || date[4] != '-' || date[7] != '-'
		|| dotCount > 1 || std::count_if(amount.begin(), amount.end(), isDigit) < static_cast<long int>(amount.size()) - dotCount)
		throw std::runtime_error("bad input => " + lineStore);

	char * dateArray;
	unsigned int year = std::strtol(date.c_str(), &dateArray, 10);
	bool isLeapYear = !(year % 400) || (!(year % 4) && year % 100);

	unsigned int month = std::strtol(++dateArray, &dateArray, 10);
	if (month > 12)
		throw std::range_error("date is non existant => " + date);

	unsigned int day = std::strtol(++dateArray, &dateArray, 10);
	if (!day || day > 31 || (day > 30 && (month == 4 || month == 6 || month == 9 || month == 11))
		|| (((day > 29 && isLeapYear) || (day > 28 && !isLeapYear)) && month == 2))
			throw std::range_error("date is non existant => " + date);

	float amountValue = std::atof(amount.c_str());
	if (amountValue < 0)
		throw std::range_error("not a positive number.");
	if (amountValue > 1000)
		throw std::range_error("too large a number.");

	std::pair<std::string, float> validatedValues;
	
	validatedValues.first = date;
	validatedValues.second = amountValue;
	precisionCount = dotCount ? amount.size() - amount.find(".") - 1: 0;

	return validatedValues;
}

void BitcoinExchange::printValue(std::pair<std::string, float> dateValuePair) throw(std::runtime_error) {
	std::map<std::string, float>::iterator exchangeRate = this->_exchangeDatabase.begin();
	while (exchangeRate != this->_exchangeDatabase.end()) {
		if (dateValuePair.first < exchangeRate->first)
			break ;
		++exchangeRate;
	}
	if (exchangeRate-- == this->_exchangeDatabase.begin())
		throw std::range_error("date is non existant => " + dateValuePair.first);
	std::cout << dateValuePair.first << " => " << std::setprecision(precisionCount) << dateValuePair.second << " = " << std::setprecision(2) << dateValuePair.second * exchangeRate->second << '\n';
}
