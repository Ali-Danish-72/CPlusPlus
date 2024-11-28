/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdanish <mdanish@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 18:12:23 by mdanish           #+#    #+#             */
/*   Updated: 2024/11/28 19:11:24 by mdanish          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "../includes/HumanB.hpp"

HumanB::HumanB(std::string name) : _name(name), _weapon(NULL) {
	return;
}

HumanB::HumanB(std::string name, Weapon &weapon) : _name(name), _weapon(&weapon){
	return;
}

HumanB::~HumanB(void) {
	return;
}

void HumanB::attack(void) const {
	std::cout << this->_name;
	std::cout << (this->_weapon ? "attacks with their " + this->_weapon->getType() + '\n'
	: "doesn't have a weapon.\n");
}

void HumanB::setWeapon(Weapon &weapon) {
	this->_weapon = &weapon;
}
