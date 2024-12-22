/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdanish <mdanish@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 15:44:16 by mdanish           #+#    #+#             */
/*   Updated: 2024/12/22 16:18:19 by mdanish          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ScavTrap.hpp"

ScavTrap::ScavTrap(void) : ClapTrap() {
	std::cout << "ScavTrap Default Constructor called.\n";
	this->_hitPoints = 100;
	this->_energyPoints = 50;
	this->_attackDamage = 20;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name) {
	std::cout << "ScavTrap Parametric Constructor called.\n";
	this->_hitPoints = 100;
	this->_energyPoints = 50;
	this->_attackDamage = 20;
}

ScavTrap::ScavTrap(const ScavTrap & other) : ClapTrap(other){
	std::cout << "ScavTrap Copy Constructor called.\n";
	*this = other;
	return;
}

ScavTrap & ScavTrap::operator = (const ScavTrap & other) {
	std::cout << "ScavTrap Copy assignment operator called.\n";
	if (&other != this) {
		this->_name = other._name;
		this->_hitPoints = other._hitPoints;
		this->_energyPoints = other._energyPoints;
		this->_attackDamage = other._attackDamage;
	}
	return *this;
}

ScavTrap::~ScavTrap(void) {
	std::cout << "ScavTrap Destructor called.\n";
}

void ScavTrap::attack(const std::string & target) {
	if (this->_hitPoints < 1)
		return (void)(std::cout << "ScavTrap " << this->_name << " has no health left.\n");
	if (!this->_energyPoints)
		return (void)(std::cout << "ScavTrap " << this->_name << " has no energy left.\n");
	this->_energyPoints--;
	std::cout << "ScavTrap " << this->_name << " attacks " << target << ", causing " << this->_attackDamage << " points of damage!\n";
}

void ScavTrap::guardGate(void) {
	std::cout << "ScavTrap " << this->getName() << " is now in Gate Keeper mode.\n";
}
