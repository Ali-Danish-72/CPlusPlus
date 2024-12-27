/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdanish <mdanish@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 07:02:12 by mdanish           #+#    #+#             */
/*   Updated: 2024/12/27 15:34:23 by mdanish          ###   ########.fr       */
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

void WrongCat::addIdea(std::string idea) {
	static int index;

	if (!this->_brain) std::cout << "There is no brain.\n";
	else if (index == 100) std::cout << "The brain is full.\n";
	else this->_brain->addIdea(idea, index++);
}

std::string WrongCat::retrieveIdea(int index) const {
	if (!this->_brain) return (std::cout << "There is no brain.\n", "");
	if (index > 99 || index < 10) return (std::cout << "Invalid index prompted\n", "");
	return this->_brain->retrieveIdea(index);
}
