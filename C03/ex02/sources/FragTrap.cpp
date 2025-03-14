/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdanish <mdanish@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 16:12:39 by mdanish           #+#    #+#             */
/*   Updated: 2024/12/22 16:18:19 by mdanish          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/FragTrap.hpp"

FragTrap::FragTrap(void) : ClapTrap() {
	std::cout << "FragTrap Default Constructor called.\n";
	this->_hitPoints = 100;
	this->_energyPoints = 100;
	this->_attackDamage = 30;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name) {
	std::cout << "FragTrap Parametric Constructor called.\n";
	this->_hitPoints = 100;
	this->_energyPoints = 100;
	this->_attackDamage = 30;
}

FragTrap::FragTrap(const FragTrap & other) : ClapTrap(other){
	std::cout << "FragTrap Copy Constructor called.\n";
	*this = other;
	return;
}

FragTrap & FragTrap::operator = (const FragTrap & other) {
	std::cout << "FragTrap Copy assignment operator called.\n";
	if (&other != this) {
		this->_name = other._name;
		this->_hitPoints = other._hitPoints;
		this->_energyPoints = other._energyPoints;
		this->_attackDamage = other._attackDamage;
	}
	return *this;
}

FragTrap::~FragTrap(void) {
	std::cout << "FragTrap Destructor called.\n";
}

void FragTrap::attack(const std::string & target) {
	if (this->_hitPoints < 1)
		return (void)(std::cout << "FragTrap " << this->_name << " has no health left.\n");
	if (!this->_energyPoints)
		return (void)(std::cout << "FragTrap " << this->_name << " has no energy left.\n");
	this->_energyPoints--;
	std::cout << "FragTrap " << this->_name << " attacks " << target << ", causing " << this->_attackDamage << " points of damage!\n";
}

void FragTrap::highFivesGuys(void) {
	std::cout << "FragTrap " << this->getName() << " high fives everyone.\n";
}
