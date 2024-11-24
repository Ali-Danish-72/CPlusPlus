/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdanish <mdanish@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 18:12:04 by mdanish           #+#    #+#             */
/*   Updated: 2024/11/24 18:47:34 by mdanish          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Weapon.hpp"
#include <iostream>

class HumanB {
	private:
		Weapon *_weapon;
		std::string _name;
		HumanB(void);
	
	public:
		HumanB(std::string name);
		HumanB(std::string name, Weapon &weapon);
		~HumanB(void);
		void attack(void) const;
		void setWeapon(Weapon &weapon);
};
