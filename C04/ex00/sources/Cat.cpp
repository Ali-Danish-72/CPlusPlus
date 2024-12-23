/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdanish <mdanish@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/22 23:05:57 by mdanish           #+#    #+#             */
/*   Updated: 2024/12/24 03:26:30 by mdanish          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Cat.hpp"
#include <iostream>

Cat::Cat(void) : Animal("cat") {
	std::cout << "Default Cat Constructor called.\n";
}

Cat::Cat(const Cat & other) : Animal(other) {
	std::cout << "Copy Cat Constructor called.\n";
	*this = other;
}

Cat & Cat::operator = (const Cat & other) {
	std::cout << "Copy Cat Assignment Operator called.\n";
	if (&other != this)
		this->_type = other._type;
	return *this;
}

Cat::~Cat(void) {
	std::cout << "Cat Destructor called.\n";
}

void Cat::makeSound(void) const {
	std::cout << "Meow\n";
}
