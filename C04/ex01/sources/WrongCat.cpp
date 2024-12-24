/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdanish <mdanish@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 07:02:12 by mdanish           #+#    #+#             */
/*   Updated: 2024/12/24 03:48:37 by mdanish          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/WrongCat.hpp"
#include <iostream>

WrongCat::WrongCat(void) : WrongAnimal("cat") {
	std::cout << "Default WrongCat Constructor called.\n";
	this->_brain = new Brain();
	if (!this->_brain) std::cerr << "The allocation for Brain failed.\n";
}

WrongCat::WrongCat(const WrongCat & other) : WrongAnimal(other) {
	std::cout << "Copy WrongCat Constructor called.\n";
	*this = other;
}

WrongCat & WrongCat::operator = (const WrongCat & other) {
	std::cout << "Copy WrongCat Assignment Operator called.\n";
	if (&other != this) {
		this->_brain = new Brain(*other._brain);
		if (!this->_brain) std::cerr << "The allocation for Brain failed.\n";
		this->_type = other._type;
	}
	return *this;
}

WrongCat::~WrongCat(void) {
	std::cout << "WrongCat Destructor called.\n";
	delete this->_brain;
}

void WrongCat::makeSound(void) const {
	std::cout << "Meow\n";
}