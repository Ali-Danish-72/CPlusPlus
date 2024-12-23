/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdanish <mdanish@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/22 22:45:27 by mdanish           #+#    #+#             */
/*   Updated: 2024/12/24 03:26:09 by mdanish          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Animal.hpp"
#include <iostream>

Animal::Animal(void) : _type("animal") {
	std::cout << "Default Animal Constructor called.\n";
}

Animal::Animal(std::string type) : _type(type) {
	std::cout << "Parametric Animal Constructor called.\n";
}

Animal::Animal(const Animal & other) {
	std::cout << "Copy Animal Constructor called.\n";
	*this = other;
}

Animal & Animal::operator = (const Animal & other) {
	std::cout << "Copy Animal Assignment Operator called.\n";
	if (&other != this)
		this->_type = other._type;
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
