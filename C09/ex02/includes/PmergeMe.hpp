/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdanish <mdanish@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 15:54:34 by mdanish           #+#    #+#             */
/*   Updated: 2025/02/27 19:09:26 by mdanish          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <cctype>
#include <ctime>
#include <deque>
#include <iomanip>
#include <iostream>
#include <stdexcept>
#include <sstream>
#include <string>
#include <utility>
#include <vector>

template <typename Iterator> inline bool isSorted(Iterator begin, Iterator end) {
	while (++begin != end)
		if (*begin < *(begin - 1))
			return false;
	return true;
}

template <typename Iterator> void sortThePairs(Iterator begin, Iterator end) {
	bool sorted;

	for (; begin < end; --end) {
		sorted = true;
		for (Iterator it = begin; it < end - 1; ++it)
			if (it->second > (it + 1)->second)
				std::swap(*it, *(it + 1)), sorted = false;
		if (sorted)
			break;
	}
}

class PmergeMe {
	private:
		PmergeMe(const PmergeMe & other);
		PmergeMe & operator = (const PmergeMe & other);

		std::deque<int> _dequeOfNumbers;
		std::clock_t _startDeque;
		std::clock_t _endDeque;

		std::vector<int> _vectorOfNumbers;
		std::clock_t _startVector;
		std::clock_t _endVector;

		int _sizeOfArray;

		void returnTheNumbersToTheMainDeque(std::deque<int> & dequeOfTheSmallerSplit) throw();
		void returnTheNumbersToTheMainVector(std::vector<int> & vectorOfTheSmallerSplit) throw();

	public:
		PmergeMe(void);
		~PmergeMe(void);

		double getTimeForDeque(void) throw();
		double getTimeForVector(void) throw();
		int getSize(void) throw();

		void printTheNumbers(std::string message) throw();
		void sortTheDeque(void) throw();
		void sortTheVector(void) throw();
		void verification(char **values) throw(std::runtime_error);
};
