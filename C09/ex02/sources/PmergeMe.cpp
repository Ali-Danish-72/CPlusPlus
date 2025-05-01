/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdanish <mdanish@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 20:23:09 by mdanish           #+#    #+#             */
/*   Updated: 2025/02/27 19:09:50 by mdanish          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/PmergeMe.hpp"

PmergeMe::PmergeMe() : _sizeOfArray(0) {}

PmergeMe::~PmergeMe() {}

double PmergeMe::getTimeForDeque(void) throw() {
	return static_cast<double>(this->_endDeque - this->_startDeque) / CLOCKS_PER_SEC ;
}

double PmergeMe::getTimeForVector(void) throw() {
	return static_cast<double>(this->_endVector - this->_startVector) / CLOCKS_PER_SEC;
}

int PmergeMe::getSize(void) throw() {
	return this->_sizeOfArray;
}

void PmergeMe::printTheNumbers(std::string message) throw() {
	std::cout << message;
	if (message == "Before: ")
		for (std::vector<int>::iterator it = this->_vectorOfNumbers.begin(); it != this->_vectorOfNumbers.end() ;++it)
			std::cout << *it << ' ';
	else
		for (std::deque<int>::iterator it = this->_dequeOfNumbers.begin(); it != this->_dequeOfNumbers.end() ;++it)
			std::cout << *it << ' ';
	std::cout << std::endl;
}

static int createJacobsthalNumber(int index) {
	if (index < 2) return index;
	return createJacobsthalNumber(index - 1) + (2 * createJacobsthalNumber(index - 2));
}

void PmergeMe::returnTheNumbersToTheMainDeque(std::deque<int> & dequeOfTheSmallerSplit) throw() {
	int sizeOfTheSmallerSplit = dequeOfTheSmallerSplit.size();
	int jacobsthalIndex = 3;
	int jacobsthalNumber = createJacobsthalNumber(jacobsthalIndex);
	std::deque<int> jacobsthalSequence;
	while (jacobsthalNumber < sizeOfTheSmallerSplit - 1) {
		jacobsthalSequence.push_back(jacobsthalNumber);
		jacobsthalNumber = createJacobsthalNumber(++jacobsthalIndex);
	}

	int iteration = -1;
	bool toUseJacobsthalSequence = true;
	int valueStore;
	this->_dequeOfNumbers.insert(this->_dequeOfNumbers.begin(), dequeOfTheSmallerSplit.front());
	this->_dequeOfNumbers.erase(this->_dequeOfNumbers.cbegin());
	while (++iteration <= sizeOfTheSmallerSplit) {
		if (toUseJacobsthalSequence && jacobsthalSequence.size()) {
			valueStore = dequeOfTheSmallerSplit[jacobsthalSequence.front()];
			jacobsthalSequence.erase(jacobsthalSequence.cbegin());
			toUseJacobsthalSequence = false;
		} else {
			if (!iteration)
				continue;
			valueStore = dequeOfTheSmallerSplit[iteration - 1];
			toUseJacobsthalSequence = true;
		}
		this->_dequeOfNumbers.insert(std::upper_bound(this->_dequeOfNumbers.begin(), this->_dequeOfNumbers.end(), valueStore), valueStore);
	}
}

void PmergeMe::sortTheDeque(void) throw() {
	this->_startDeque = std::clock();
	if (isSorted(this->_dequeOfNumbers.begin(), this->_dequeOfNumbers.end()))
		return (void)(this->_endDeque = std::clock());

	std::deque<std::pair<int, int> > dequeOfPairs;
	for (std::deque<int>::iterator it = this->_dequeOfNumbers.begin(); it < this->_dequeOfNumbers.end() - 1; it += 2)
		dequeOfPairs.push_back(*it > *(it + 1) ? std::make_pair(*(it + 1), *it) : std::make_pair(*it, *(it + 1)));
	sortThePairs(dequeOfPairs.begin(), dequeOfPairs.end());

	std::deque<int> dequeOfTheSmallerSplit;
	int oddStore = this->_dequeOfNumbers.size() % 2 ? this->_dequeOfNumbers.back() : -1;
	this->_dequeOfNumbers.clear();
	for (std::deque<std::pair<int, int> >::iterator it = dequeOfPairs.begin(); it != dequeOfPairs.end(); ++it) {
		this->_dequeOfNumbers.push_back(it->second);
		dequeOfTheSmallerSplit.push_back(it->first);
	}
	if (oddStore != -1)
		dequeOfTheSmallerSplit.push_back(oddStore);

	returnTheNumbersToTheMainDeque(dequeOfTheSmallerSplit);
	this->_endDeque = std::clock();
}

void PmergeMe::returnTheNumbersToTheMainVector(std::vector<int> & vectorOfTheSmallerSplit) throw() {
	int sizeOfTheSmallerSplit = vectorOfTheSmallerSplit.size();
	int jacobsthalIndex = 3;
	int jacobsthalNumber = createJacobsthalNumber(jacobsthalIndex);
	std::vector<int> jacobsthalSequence;
	while (jacobsthalNumber < sizeOfTheSmallerSplit - 1) {
		jacobsthalSequence.push_back(jacobsthalNumber);
		jacobsthalNumber = createJacobsthalNumber(++jacobsthalIndex);
	}

	int iteration = -1;
	bool toUseJacobsthalSequence = true;
	int valueStore;
	this->_vectorOfNumbers.insert(this->_vectorOfNumbers.begin(), vectorOfTheSmallerSplit.front());
	this->_vectorOfNumbers.erase(this->_vectorOfNumbers.cbegin());
	while (++iteration <= sizeOfTheSmallerSplit) {
		if (toUseJacobsthalSequence && jacobsthalSequence.size()) {
			valueStore = vectorOfTheSmallerSplit[jacobsthalSequence.front()];
			jacobsthalSequence.erase(jacobsthalSequence.cbegin());
			toUseJacobsthalSequence = false;
		} else {
			if (!iteration)
				continue;
			valueStore = vectorOfTheSmallerSplit[iteration - 1];
			toUseJacobsthalSequence = true;
		}
		this->_vectorOfNumbers.insert(std::upper_bound(this->_vectorOfNumbers.begin(), this->_vectorOfNumbers.end(), valueStore), valueStore);
	}
}

void PmergeMe::sortTheVector(void) throw() {
	this->_startVector = std::clock();
	if (isSorted(this->_vectorOfNumbers.begin(), this->_vectorOfNumbers.end()))
		return (void)(this->_endVector = std::clock());

	std::vector<std::pair<int, int> > vectorOfPairs;
	for (std::vector<int>::iterator it = this->_vectorOfNumbers.begin(); it < this->_vectorOfNumbers.end() - 1; it += 2)
		vectorOfPairs.push_back(*it > *(it + 1) ? std::make_pair(*(it + 1), *it) : std::make_pair(*it, *(it + 1)));
	sortThePairs(vectorOfPairs.begin(), vectorOfPairs.end());

	std::vector<int> vectorOfTheSmallerSplit;
	int oddStore = this->_vectorOfNumbers.size() % 2 ? this->_vectorOfNumbers.back() : -1;
	this->_vectorOfNumbers.clear();
	for (std::vector<std::pair<int, int> >::iterator it = vectorOfPairs.begin(); it != vectorOfPairs.end(); ++it) {
		this->_vectorOfNumbers.push_back(it->second);
		vectorOfTheSmallerSplit.push_back(it->first);
	}
	if (oddStore != -1)
		vectorOfTheSmallerSplit.push_back(oddStore);

	returnTheNumbersToTheMainVector(vectorOfTheSmallerSplit);
	this->_endVector = std::clock();
}

void PmergeMe::verification(char **values) throw(std::runtime_error) {
	int value;
	for (int i = 1; values[i]; ++i) {
		std::istringstream argument(values[i]);
		if (!std::isdigit(values[i][0]) || (argument >> value).fail() || !argument.eof() || value < 0)
			throw (std::runtime_error("Invalid argument: " + std::string(values[i])));
		this->_vectorOfNumbers.push_back(value);
		this->_dequeOfNumbers.push_back(value);
	}
	this->_sizeOfArray = this->_vectorOfNumbers.size();
}
