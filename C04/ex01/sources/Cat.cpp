/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdanish <mdanish@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/22 23:05:57 by mdanish           #+#    #+#             */
/*   Updated: 2024/12/27 15:34:16 by mdanish          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Cat.hpp"
#include <iostream>

Cat::Cat(void) : Animal("cat") {
	std::cout << "Default Cat Constructor called.\n";
	this->_brain = new Brain();
	if (!this->_brain) std::cerr << "The allocation for Brain failed.\n";
}

Cat::Cat(const Cat & other) : Animal(other) {
	std::cout << "Copy Cat Constructor called.\n";
	*this = other;
}

Cat & Cat::operator = (const Cat & other) {
	std::cout << "Copy Cat Assignment Operator called.\n";
	if (&other != this) {
		this->_brain = new Brain(*other._brain);
		if (!this->_brain) std::cerr << "The allocation for Brain failed.\n";
	}
	return *this;
}

Cat::~Cat(void) {
	std::cout << "Cat Destructor called.\n";
	delete this->_brain;
}

void Cat::makeSound(void) const {
	std::cout << "Meow\n";
}

void Cat::addIdea(std::string idea) {
	static int index;

	if (!this->_brain) std::cout << "There is no brain.\n";
	else if (index == 100) std::cout << "The brain is full.\n";
	else this->_brain->addIdea(idea, index++);
}

std::string Cat::retrieveIdea(int index) const {
	if (!this->_brain) return (std::cout << "There is no brain.\n", "");
	if (index > 99 || index < 10) return (std::cout << "Invalid index prompted\n", "");
	return this->_brain->retrieveIdea(index);
}
