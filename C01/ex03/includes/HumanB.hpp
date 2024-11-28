/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdanish <mdanish@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 18:12:04 by mdanish           #+#    #+#             */
/*   Updated: 2024/11/28 19:22:27 by mdanish          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Weapon.hpp"

class HumanB {
	private:
		HumanB(void);

		std::string _name;
		Weapon *_weapon;

	public:
		HumanB(std::string name);
		HumanB(std::string name, Weapon &weapon);
		~HumanB(void);

		void attack(void) const;
		void setWeapon(Weapon &weapon);
};
