/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdanish <mdanish@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 11:21:08 by mdanish           #+#    #+#             */
/*   Updated: 2024/11/28 18:56:13 by mdanish          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>

class Zombie {
	private:
		std::string _name;

	public:
		Zombie(void);
		Zombie(std::string name);
		~Zombie(void);

		void announce(void);
		void setName(std::string name);
};

Zombie	*zombieHorde(int numberOfZombies, std::string name);
