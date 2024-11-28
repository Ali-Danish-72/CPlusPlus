/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdanish <mdanish@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 17:57:25 by mdanish           #+#    #+#             */
/*   Updated: 2024/11/28 18:59:00 by mdanish          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "../includes/HumanA.hpp"

HumanA::HumanA(std::string name, Weapon &weapon) : _name(name), _weapon(weapon) {
	return;
}

HumanA::~HumanA(void) {
	return;
}

void HumanA::attack(void) const {
	std::cout << this->_name << "attacks with their " << this->_weapon.getType() << '\n';
}
