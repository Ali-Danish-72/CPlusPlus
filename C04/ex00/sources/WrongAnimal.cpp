/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdanish <mdanish@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 06:57:39 by mdanish           #+#    #+#             */
/*   Updated: 2024/12/24 03:27:06 by mdanish          ###   ########.fr       */
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
