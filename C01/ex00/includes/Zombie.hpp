/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdanish <mdanish@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 11:21:08 by mdanish           #+#    #+#             */
/*   Updated: 2024/11/28 18:55:07 by mdanish          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>

class Zombie {
	private:
		Zombie(void);

		std::string _name;

	public:
		Zombie(std::string name);
		~Zombie(void);

		void announce(void);
};

void randomChump(std::string name);
Zombie *newZombie(std::string name);
