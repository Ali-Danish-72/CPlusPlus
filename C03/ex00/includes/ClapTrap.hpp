/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdanish <mdanish@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 12:45:20 by mdanish           #+#    #+#             */
/*   Updated: 2024/12/12 15:42:29 by mdanish          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

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
		void status(void) const;
};
