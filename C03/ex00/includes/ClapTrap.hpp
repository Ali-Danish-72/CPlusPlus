/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdanish <mdanish@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 12:45:20 by mdanish           #+#    #+#             */
/*   Updated: 2024/12/20 22:10:18 by mdanish          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <string>

class ClapTrap {
	private:
		std::string _name;
		int _hitPoints;
		int _energyPoints;
		int _attackDamage;

	public:
		ClapTrap(void);
		ClapTrap(std::string name);
		ClapTrap(const ClapTrap & other);
		~ClapTrap(void);
		ClapTrap & operator = (const ClapTrap & other);

		void attack(const std::string& target);
		void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);

		int getAttackDamage(void) const;
		int getEnergyPoints(void) const;
		int getHitPoints(void) const;
		const std::string getName(void) const;
};

std::ostream & operator << (std::ostream & out, ClapTrap const & other);
