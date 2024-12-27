/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdanish <mdanish@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/22 23:13:05 by mdanish           #+#    #+#             */
/*   Updated: 2024/12/27 15:34:06 by mdanish          ###   ########.fr       */
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

void Dog::addIdea(std::string idea) {
	static int index;

	if (!this->_brain) std::cout << "There is no brain.\n";
	else if (index == 100) std::cout << "The brain is full.\n";
	else this->_brain->addIdea(idea, index++);
}

std::string Dog::retrieveIdea(int index) const {
	if (!this->_brain) return (std::cout << "There is no brain.\n", "");
	if (index > 99 || index < 10) return (std::cout << "Invalid index prompted\n", "");
	return this->_brain->retrieveIdea(index);
}
