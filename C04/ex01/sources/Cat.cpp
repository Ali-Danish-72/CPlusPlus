/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdanish <mdanish@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/22 23:05:57 by mdanish           #+#    #+#             */
/*   Updated: 2024/12/24 04:17:04 by mdanish          ###   ########.fr       */
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
		this->_type = other._type;
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
