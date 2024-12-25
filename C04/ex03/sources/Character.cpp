/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdanish <mdanish@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/25 19:43:30 by mdanish           #+#    #+#             */
/*   Updated: 2024/12/25 23:21:10 by mdanish          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Character.hpp"
#include <iostream>

Character::Character(std::string const & name) : _name(name), _droppedCount(0) {
	std::cout << "Default Character Constructor called.\n";
	for (int i = 0; i < 4; i++)
		this->_materials[i] = NULL;
	for (int i = 0; i < 500; i++)
		this->_dropped[i] = NULL;
}

Character::Character(Character const & other) : _name(other._name) {
	std::cout << "Copy Character Constructor called.\n";
	*this = other;
}

Character::~Character(void) {
	std::cout << "Character Destructor called.\n";
	for (int i = 0; i < 4; i++)
		delete this->_materials[i];
	while (this->_droppedCount--)
		delete this->_dropped[this->_droppedCount];
}

AMateria * typeBasedAllocation(AMateria * material);

Character & Character::operator = (Character const & other) {
	if (this != &other) {
		for (int i = 0; i < 4; i++) {
			delete this->_materials[i];
			this->_materials[i] = typeBasedAllocation(other._materials[i]);
		}
		while (this->_droppedCount--) {
			delete this->_dropped[this->_droppedCount];
			this->_dropped[this->_droppedCount] = NULL;
		}
		for (int i = 0; i < other._droppedCount; i++)
			this->_dropped[i] = typeBasedAllocation(other._dropped[i]);
	}
	return *this;
}

std::string const & Character::getName() const {
	return this->_name;
}

void Character::equip(AMateria * m) {
	for (int i = 0; i < 4; i++)
		if (!this->_materials[i]) {
			this->_materials[i] = m;
			break ;
		}
}

void Character::unequip(int idx) {
	if (idx > -1 && idx < 4 && this->_materials[idx]) {
		this->_dropped[this->_droppedCount++] = this->_materials[idx];
		this->_materials[idx] = NULL;
	}
}

void Character::use(int idx, ICharacter & target) {
	if (idx > -1 && idx < 4 && this->_materials[idx])
		this->_materials[idx]->use(target);
}
