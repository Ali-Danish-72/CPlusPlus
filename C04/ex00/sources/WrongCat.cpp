/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdanish <mdanish@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 07:02:12 by mdanish           #+#    #+#             */
/*   Updated: 2024/12/27 15:22:45 by mdanish          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/WrongCat.hpp"
#include <iostream>

WrongCat::WrongCat(void) : WrongAnimal("(wrong)cat") {
	std::cout << "Default WrongCat Constructor called.\n";
}

WrongCat::WrongCat(const WrongCat & other) : WrongAnimal(other) {
	std::cout << "Copy WrongCat Constructor called.\n";
	*this = other;
}

WrongCat & WrongCat::operator = (const WrongCat & other) {
	std::cout << "Copy WrongCat Assignment Operator called.\n";
	if (&other != this)
		this->_type = other._type;
	return *this;
}

WrongCat::~WrongCat(void) {
	std::cout << "WrongCat Destructor called.\n";
}

void WrongCat::makeSound(void) const {
	std::cout << "Meow\n";
}
