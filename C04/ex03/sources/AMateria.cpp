/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdanish <mdanish@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/25 16:53:06 by mdanish           #+#    #+#             */
/*   Updated: 2024/12/26 23:03:19 by mdanish          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/AMateria.hpp"
#include <iostream>

AMateria::AMateria(void) : _type("Default") {
	std::cout << "Default AMateria Constructor called.\n";
}

AMateria::AMateria(std::string const & type) : _type(type) {
	std::cout << "Parametric AMateria Constructor called.\n";
}

AMateria::AMateria(AMateria const & other) {
	std::cout << "Copy AMateria Constructor called.\n";
	*this = other;
}

AMateria::~AMateria(void) {
	std::cout << "AMateria Destructor called.\n";
}

AMateria & AMateria::operator = (AMateria const & other) {
	std::cout << "Copy AMateria Assignment Operator called.\n";
	if (this != &other)
		this->_type = other._type;
	return *this;
}

std::string const & AMateria::getType(void) const {
	return this->_type;
}

void AMateria::use(ICharacter & target) {
	std::cout << "* Materia " << this->getType() << " uses its abilities on " << target.getName() << " *\n";
}
