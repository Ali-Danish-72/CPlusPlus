/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdanish <mdanish@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/22 22:45:27 by mdanish           #+#    #+#             */
/*   Updated: 2024/12/24 23:03:21 by mdanish          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Animal.hpp"
#include <iostream>

Animal::Animal(void) : _type("animal"), _brain(NULL) {
	std::cout << "Default Animal Constructor called.\n";
}

Animal::Animal(std::string type) : _type(type), _brain(NULL) {
	std::cout << "Parametric Animal Constructor called.\n";
}

Animal::Animal(const Animal & other) {
	std::cout << "Copy Animal Constructor called.\n";
	*this = other;
}

Animal & Animal::operator = (const Animal & other) {
	std::cout << "Copy Animal Assignment Operator called.\n";
	if (&other != this) {
		if (other._brain)
			_brain = new Brain(*other._brain);
		this->_type = other._type;
	}
	return *this;
}

Animal::~Animal(void) {
	std::cout << "Animal Destructor called.\n";
}

void Animal::makeSound(void) const {
	std::cout << "* Generic " << getType() << " Sounds *\n";
}

const std::string & Animal::getType(void) const {
	return this->_type;
}

void Animal::addIdea(std::string idea) {
	static int index;

	if (!this->_brain) std::cout << "There is no brain.\n";
	else if (index == 100) std::cout << "The brain is full.\n";
	else this->_brain->addIdea(idea, index++);
}
std::string Animal::retrieveIdea(int index) const {
	if (!this->_brain) return (std::cout << "There is no brain.\n", "");
	if (index > 100 || index < 1) return (std::cout << "Invalid index prompted\n", "");
	return this->_brain->retrieveIdea(--index);
}
