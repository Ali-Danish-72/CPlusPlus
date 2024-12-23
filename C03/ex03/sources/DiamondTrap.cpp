/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdanish <mdanish@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 19:30:03 by mdanish           #+#    #+#             */
/*   Updated: 2024/12/24 03:38:31 by mdanish          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/DiamondTrap.hpp"

DiamondTrap::DiamondTrap(void) : ClapTrap("Nameless_clap_name"), _name("Nameless") {
	std::cout << "DiamondTrap Default Constructor called.\n";
	ClapTrap::_attackDamage = FragTrap::_attackDamage;
	ClapTrap::_hitPoints = FragTrap::_hitPoints;
}

DiamondTrap::DiamondTrap(std::string name) : ClapTrap(name + "_clap_name"), _name(name) {
	std::cout << "DiamondTrap Parametric Constructor called.\n";
	ClapTrap::_attackDamage = FragTrap::_attackDamage;
	ClapTrap::_hitPoints = FragTrap::_hitPoints;
}

DiamondTrap::DiamondTrap(const DiamondTrap & other) : ClapTrap(other), FragTrap(other), ScavTrap(other) {
	std::cout << "DiamondTrap Copy Constructor called.\n";
	*this = other;
}

DiamondTrap & DiamondTrap::operator = (const DiamondTrap & other) {
	std::cout << "DiamondTrap Copy Assignment Operator called.\n";
	if (&other != this) {
		this->_name = other._name;
		this->_attackDamage = other._attackDamage;
		this->_energyPoints = other._energyPoints;
		this->_hitPoints = other._hitPoints;
	}
	return *this;
}

DiamondTrap::~DiamondTrap(void) {
	std::cout << "DiamondTrap Destructor called.\n";
}

void DiamondTrap::whoAmI(void) {
	std::cout << "I am " << this->_name << ", also known as " << ClapTrap::_name << ".\n";
}

void DiamondTrap::attack(const std::string & target) {
	ScavTrap::attack(target);
}
