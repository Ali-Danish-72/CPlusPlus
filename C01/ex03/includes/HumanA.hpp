/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdanish <mdanish@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 17:34:46 by mdanish           #+#    #+#             */
/*   Updated: 2024/11/28 19:21:28 by mdanish          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Weapon.hpp"

class HumanA {
	private:
		HumanA(void);

		std::string _name;
		Weapon &_weapon;
	
	public:
		HumanA(std::string name, Weapon &weapon);
		~HumanA(void);

		void attack(void) const;
};
