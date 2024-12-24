/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdanish <mdanish@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 07:33:28 by mdanish           #+#    #+#             */
/*   Updated: 2024/12/24 22:40:30 by mdanish          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Brain.hpp"
#include <iostream>

Brain::Brain(void) {
	std::cout << "Default Brain Constructor called.\n";
}

Brain::Brain(const Brain & other) {
	std::cout << "Default Brain Constructor called.\n";
	*this = other;
}

Brain::~Brain(void) {
	std::cout << "Brain Destructor called.\n";
}

Brain & Brain::operator = (const Brain & other) {
	std::cout << "Copy Brain Assignment Operator called.\n";
	if (this != &other)
		for (int i = 0; i < 100; i++)
			this->_ideas[i] = other._ideas[i];
	return *this;
}

void Brain::addIdea(std::string idea, int index) {
	if (index > -1 && index < 100 && this->_ideas[index] == "")
		this->_ideas[index] = idea;
	else if (index > -1 && index < 100)
		std::cout << "That part of the brain already contains an idea, would you like to store the idea elsewhere?\n";
	else
		std::cout << "Can't access the brain with that index, please provide a valid index.\n";
}

std::string Brain::retrieveIdea(int index) const {
	return this->_ideas[index];
}
