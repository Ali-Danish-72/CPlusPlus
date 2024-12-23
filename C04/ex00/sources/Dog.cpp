/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdanish <mdanish@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/22 23:13:05 by mdanish           #+#    #+#             */
/*   Updated: 2024/12/24 03:26:46 by mdanish          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Dog.hpp"
#include <iostream>

Dog::Dog(void) : Animal("dog") {
	std::cout << "Default Dog Constructor called.\n";
}

Dog::Dog(const Dog & other) : Animal(other) {
	std::cout << "Copy Dog Constructor called.\n";
	*this = other;
}

Dog & Dog::operator = (const Dog & other) {
	std::cout << "Copy Dog Assignment Operator called.\n";
	if (&other != this)
		this->_type = other._type;
	return *this;
}

Dog::~Dog(void) {
	std::cout << "Dog Destructor called.\n";
}

void Dog::makeSound(void) const {
	std::cout << "Woof\n";
}
