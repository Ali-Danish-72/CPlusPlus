/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdanish <mdanish@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 06:57:39 by mdanish           #+#    #+#             */
/*   Updated: 2024/12/24 22:41:18 by mdanish          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/WrongAnimal.hpp"
#include <iostream>

WrongAnimal::WrongAnimal(void) : _type("(wrong)animal") {
	std::cout << "Default WrongAnimal Constructor called.\n";
}

WrongAnimal::WrongAnimal(std::string type) : _type(type) {
	std::cout << "Parametric WrongAnimal Constructor called.\n";
}

WrongAnimal::WrongAnimal(const WrongAnimal & other) {
	std::cout << "Copy WrongAnimal Constructor called.\n";
	*this = other;
}

WrongAnimal & WrongAnimal::operator = (const WrongAnimal & other) {
	std::cout << "Copy WrongAnimal Assignment Operator called.\n";
	if (&other != this)
		this->_type = other._type;
	return *this;
}

WrongAnimal::~WrongAnimal(void) {
	std::cout << "WrongAnimal Destructor called.\n";
}

void WrongAnimal::makeSound(void) const {
	std::cout << "* Generic (wrong)animal Sounds *\n";
}

const std::string & WrongAnimal::getType(void) const {
	return this->_type;
}

void WrongAnimal::addIdea(std::string idea) {
	static int index;

	if (!this->_brain) std::cout << "There is no brain.\n";
	else if (index == 100) std::cout << "The brain is full.\n";
	else this->_brain->addIdea(idea, index++);
}

std::string WrongAnimal::retrieveIdea(int index) const {
	if (!this->_brain) return (std::cout << "There is no brain.\n", "");
	return this->_brain->retrieveIdea(index);
}
