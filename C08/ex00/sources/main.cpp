/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdanish <mdanish@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 14:30:23 by mdanish           #+#    #+#             */
/*   Updated: 2025/01/20 18:12:29 by mdanish          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/easyfind.hpp"
#include <iostream>
#include <deque>
#include <list>
#include <vector>

void integerPrint(int number) {
	std::cout << number << ' ';
}

int main() {
	int toFind;

	/*		Deque		*/
	std::deque<int> integerDeque;
	integerDeque.push_back(50);
	integerDeque.push_back(10);
	integerDeque.push_front(38);
	integerDeque.push_front(42);
	toFind = 42;
	std::deque<int>::const_iterator iterationDeque = easyfind(integerDeque, toFind);
	std::cout << "The deque of numbers: ";
	std::for_each(integerDeque.begin(), integerDeque.end(), integerPrint);
	iterationDeque != integerDeque.end() ? std::cout << "\nFound an instance of: " << *iterationDeque << "\n\n" :
	std::cout << "\nCould not find an instance of: " << toFind << "\n\n";

	/*		List		*/
	std::list<int> integerList;
	integerList.insert(integerList.insert(integerList.begin(), 10), 50);
	integerList.insert(integerList.insert(integerList.begin(), 42), 38);
	toFind = 34;
	std::list<int>::const_iterator iterationList = easyfind(integerList, toFind);
	std::cout << "The list of numbers: ";
	std::for_each(integerList.begin(), integerList.end(), integerPrint);
	iterationList != integerList.end() ? std::cout << "\nFound an instance of: " << *iterationList << "\n\n" :
	std::cout << "\nCould not find an instance of: " << toFind << "\n\n";

	/*		Vector		*/
	std::vector<int> integerVector(1, 50);
	integerVector.push_back(10);
	integerVector.push_back(38);
	integerVector.push_back(42);
	toFind = 595;
	std::vector<int>::iterator iterationVector = easyfind(integerVector, toFind);
	std::cout << "The vector of numbers: ";
	std::for_each(integerVector.begin(), integerVector.end(), integerPrint);
	iterationVector != integerVector.end() ? std::cout << "\nFound an instance of: " << *iterationVector << "\n\n" :
	std::cout << "\nCould not find an instance of: " << toFind << "\n\n";
}
