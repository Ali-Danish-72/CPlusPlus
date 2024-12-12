/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdanish <mdanish@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 12:48:32 by mdanish           #+#    #+#             */
/*   Updated: 2024/12/12 15:46:26 by mdanish          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ClapTrap.hpp"
#include <iostream>

ClapTrap::ClapTrap(void) : _name("Default"), _hitPoints(10), _energyPoints(10), _attackDamage(0) {
	std::cout << "Default constructor called.\n";
	return;
}

ClapTrap::ClapTrap(std::string name) : _name(name), _hitPoints(10), _energyPoints(10), _attackDamage(0) {
	std::cout << "Parametric constructor called.\n";
	return;
}

ClapTrap::ClapTrap(const ClapTrap & other) {
	std::cout << "Copy constructor called.\n";
	*this = other;
	return;
}

ClapTrap & ClapTrap::operator = (const ClapTrap & other) {
	std::cout << "Copy assignment operator called.\n";
	this->_name = other._name;
	this->_hitPoints = other._hitPoints;
	this->_energyPoints = other._energyPoints;
	this->_attackDamage = other._attackDamage;
	return *this;
}

ClapTrap::~ClapTrap(void) {
	std::cout << "Destructor called.\n";
	return;
}

void ClapTrap::attack(const std::string &target) {
	if (!this->_hitPoints)
		return (void)(std::cout << "ClapTrap " << this->_name << " has no health left.\n");
	if (!this->_energyPoints)
		return (void)(std::cout << "ClapTrap " << this->_name << " has no energy left.\n");
	this->_energyPoints--;
	std::cout << "ClapTrap " << this->_name << " attacks " << target << ", causing " << this->_attackDamage << " points of damage!\n";
}

void ClapTrap::takeDamage(unsigned int amount) {
	if (this->_hitPoints <= 0)
		return (void)(std::cout << "ClapTrap " << this->_name << " has no more health.\n");
	std::cout << "ClapTrap " << this->_name << " took " << amount << " of damage.\n";
	this->_hitPoints -= amount;
	if (this->_hitPoints <= 0)
		std::cout << "ClapTrap " << this->_name << " has no more health.\n";
}

void ClapTrap::beRepaired(unsigned int amount) {
	if (!this->_hitPoints)
		return (void)(std::cout << "ClapTrap " << this->_name << " has no health left.\n");
	if (!this->_energyPoints)
		return (void)(std::cout << "ClapTrap " << this->_name << " has no energy left.\n");
	this->_energyPoints--;
	std::cout << "ClapTrap " << this->_name << " repaired " << amount << " of damage.\n";
	this->_hitPoints += amount;
}

int ClapTrap::getAttackDamage(void) const {
	return this->_attackDamage;
}

void ClapTrap::status(void) const {
	std::cout << this->_name << " has " << this->_hitPoints << " health and " << this->_energyPoints << " energy.\n";
}
