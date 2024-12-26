/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdanish <mdanish@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/25 19:16:46 by mdanish           #+#    #+#             */
/*   Updated: 2024/12/26 23:03:19 by mdanish          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Cure.hpp"
#include <iostream>

Cure::Cure(void) : AMateria("cure") {
	std::cout << "Default Cure Constructor called.\n";
}

Cure::Cure(Cure const & other) : AMateria(other) {
	std::cout << "Copy Cure Constructor called.\n";
}

Cure::~Cure(void) {
	std::cout << "Cure Destructor called.\n";
}

Cure & Cure::operator = (Cure const & other) {
	std::cout << "Copy Cure Assignment Operator called.\n";
	(void)other;
	return *this;
}

AMateria * Cure::clone(void) const {
	return new Cure();
}

void Cure::use(ICharacter & target) {
	std::cout << "* heals " << target.getName() << "'s wounds *\n";
}