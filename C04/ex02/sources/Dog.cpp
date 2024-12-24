/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdanish <mdanish@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/22 23:13:05 by mdanish           #+#    #+#             */
/*   Updated: 2024/12/24 22:14:49 by mdanish          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Dog.hpp"
#include <iostream>

Dog::Dog(void) : Animal("dog") {
	std::cout << "Default Dog Constructor called.\n";
	this->_brain = new Brain();
	if (!this->_brain) std::cerr << "The allocation for Brain failed.\n";
}

Dog::Dog(const Dog & other) : Animal(other) {
	std::cout << "Copy Dog Constructor called.\n";
	*this = other;
}

Dog & Dog::operator = (const Dog & other) {
	std::cout << "Copy Dog Assignment Operator called.\n";
	if (&other != this) {
		this->_brain = new Brain(*other._brain);
		if (!this->_brain) std::cerr << "The allocation for Brain failed.\n";
		this->_type = other._type;
	}
	return *this;
}

Dog::~Dog(void) {
	std::cout << "Dog Destructor called.\n";
	delete this->_brain;
}

void Dog::makeSound(void) const {
	std::cout << "Woof\n";
}
