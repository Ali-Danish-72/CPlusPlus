/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdanish <mdanish@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 16:13:01 by mdanish           #+#    #+#             */
/*   Updated: 2024/12/20 21:58:34 by mdanish          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "ClapTrap.hpp"

class FragTrap : virtual public ClapTrap {
	protected:
		int _hitPoints;
		int _attackDamage;

	public:
		FragTrap(void);
		FragTrap(std::string name);
		FragTrap(const FragTrap & other);
		~FragTrap(void);
		FragTrap & operator = (const FragTrap & other);

		void attack(const std::string &target);
		void highFivesGuys(void);
};
