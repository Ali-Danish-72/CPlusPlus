/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdanish <mdanish@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/25 16:53:06 by mdanish           #+#    #+#             */
/*   Updated: 2024/12/25 22:42:37 by mdanish          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/AMateria.hpp"
#include <iostream>

AMateria::AMateria(std::string const & type) : _type(type) {
	std::cout << "Default AMateria Constructor called.\n";
}

AMateria::~AMateria(void) {
	std::cout << "AMateria Destructor called.\n";
}

std::string const & AMateria::getType(void) const {
	return this->_type;
}

void AMateria::use(ICharacter & target) {
	std::cout << "* Materia " << this->getType() << " uses its abilities on " << target.getName() << " *\n";
}
