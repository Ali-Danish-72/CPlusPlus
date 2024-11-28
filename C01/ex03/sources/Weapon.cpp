/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdanish <mdanish@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 17:17:27 by mdanish           #+#    #+#             */
/*   Updated: 2024/11/28 19:02:16 by mdanish          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Weapon.hpp"

Weapon::Weapon(std::string type) : _type(type) {
	return;
}

Weapon::~Weapon(void) {
	return;
}

std::string const &Weapon::getType(void) const {
	return this->_type;
}

void Weapon::setType(std::string type) {
	this->_type = type;
}
