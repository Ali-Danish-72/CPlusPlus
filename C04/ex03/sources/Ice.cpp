/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdanish <mdanish@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/25 18:48:00 by mdanish           #+#    #+#             */
/*   Updated: 2024/12/26 23:03:19 by mdanish          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Ice.hpp"
#include <iostream>

Ice::Ice(void) : AMateria("ice") {
	std::cout << "Default Ice Constructor called.\n";
}

Ice::Ice(Ice const & other) : AMateria(other) {
	std::cout << "Copy Ice Constructor called.\n";
}

Ice::~Ice(void) {
	std::cout << "Ice Destructor called.\n";
}

Ice & Ice::operator = (Ice const & other) {
	std::cout << "Copy Ice Assignment Operator called.\n";
	(void)other;
	return *this;
}

AMateria * Ice::clone(void) const {
	return new Ice();
}

void Ice::use(ICharacter & target) {
	std::cout << "* shoots an ice bolt at " << target.getName() << " *\n";
}
