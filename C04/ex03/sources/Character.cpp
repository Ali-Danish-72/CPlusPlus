/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdanish <mdanish@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/25 19:43:30 by mdanish           #+#    #+#             */
/*   Updated: 2024/12/26 23:03:19 by mdanish          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Character.hpp"
#include <iostream>

Character::Character(void) : _name("Default") {
	std::cout << "Default Character Constructor called.\n";
	for (int i = 0; i < 4; i++) {
		this->_available[i] = false;
		this->_materials[i] = NULL;
	}
}

Character::Character(std::string const name) : _name(name) {
	std::cout << "Parametric Character Constructor called.\n";
	for (int i = 0; i < 4; i++) {
		this->_available[i] = false;
		this->_materials[i] = NULL;
	}
}

Character::Character(Character const & other) : _name(other._name) {
	std::cout << "Copy Character Constructor called.\n";
	*this = other;
}

Character::~Character(void) {
	std::cout << "Character Destructor called.\n";
	for (int i = 0; i < 4; i++)
		delete this->_materials[i];
}

Character & Character::operator = (Character const & other) {
	if (this != &other) {
		for (int i = 0; i < 4; i++) {
			delete this->_materials[i];
			this->_materials[i] = other._materials[i]->clone();
			if (!this->_materials[i])
				std::cerr << "Cloning has failed\n";
			this->_available[i] = other._available[i];
		}
	}
	return *this;
}

std::string const & Character::getName() const {
	return this->_name;
}

void Character::equip(AMateria * m) {
	for (int i = 0; i < 4; i++)
		if (!this->_available[i]) {
			delete this->_materials[i];
			this->_materials[i] = m;
			this->_available[i] = true;
			break ;
		}
}

void Character::unequip(int idx) {
	if (idx > -1 && idx < 4)
		this->_available[idx] = false;
}

void Character::use(int idx, ICharacter & target) {
	if (idx > -1 && idx < 4 && this->_available[idx])
		this->_materials[idx]->use(target);
}
