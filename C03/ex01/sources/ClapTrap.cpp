/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdanish <mdanish@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 12:48:32 by mdanish           #+#    #+#             */
/*   Updated: 2024/12/20 22:03:28 by mdanish          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ClapTrap.hpp"

ClapTrap::ClapTrap(void) : _name("Nameless"), _hitPoints(10), _energyPoints(10), _attackDamage(0) {
	std::cout << "ClapTrap Default Constructor called.\n";
	return;
}

ClapTrap::ClapTrap(std::string name) : _name(name), _hitPoints(10), _energyPoints(10), _attackDamage(0) {
	std::cout << "ClapTrap Parametric Constructor called.\n";
	return;
}

ClapTrap::ClapTrap(const ClapTrap & other) {
	std::cout << "ClapTrap Copy Constructor called.\n";
	*this = other;
	return;
}

ClapTrap & ClapTrap::operator = (const ClapTrap & other) {
	std::cout << "ClapTrap Copy assignment operator called.\n";
	if (&other != this) {
		this->_name = other._name;
		this->_hitPoints = other._hitPoints;
		this->_energyPoints = other._energyPoints;
		this->_attackDamage = other._attackDamage;
	}
	return *this;
}

ClapTrap::~ClapTrap(void) {
	std::cout << "ClapTrap Destructor called.\n";
	return;
}

void ClapTrap::attack(const std::string &target) {
	if (this->_hitPoints < 1)
		return (void)(std::cout << "ClapTrap " << this->_name << " has no health left.\n");
	if (!this->_energyPoints)
		return (void)(std::cout << "ClapTrap " << this->_name << " has no energy left.\n");
	this->_energyPoints--;
	std::cout << "ClapTrap " << this->_name << " attacks " << target << ", causing " << this->_attackDamage << " points of damage!\n";
}

void ClapTrap::takeDamage(unsigned int amount) {
	if (this->_hitPoints <= 0)
		return (void)(std::cout << "ClapTrap " << this->_name << " has no more health.\n");
	std::cout << "ClapTrap " << this->_name << " took " << amount << " points of damage.\n";
	this->_hitPoints -= amount;
	if (this->_hitPoints <= 0)
		std::cout << "ClapTrap " << this->_name << " has no more health.\n";
}

void ClapTrap::beRepaired(unsigned int amount) {
	if (this->_hitPoints < 1)
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

int ClapTrap::getEnergyPoints(void) const {
	return this->_energyPoints;
}

int ClapTrap::getHitPoints(void) const {
	return this->_hitPoints;
}

const std::string ClapTrap::getName(void) const {
	return this->_name;
}

std::ostream & operator << (std::ostream & out, ClapTrap const & other) {
	out << other.getName() << " has " << other.getHitPoints() << " health and " << other.getEnergyPoints() << " energy.\n";
	out << "It is also capable of dealing " << other.getAttackDamage() << " points of damage.\n";
	return out;
}
