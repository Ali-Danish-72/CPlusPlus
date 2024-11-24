/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdanish <mdanish@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 11:21:08 by mdanish           #+#    #+#             */
/*   Updated: 2024/11/24 18:01:58 by mdanish          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <string>

class Zombie {
	private:
		std::string _name;
		Zombie(void);

	public:
		Zombie(std::string name);
		~Zombie(void);
		void announce(void);
};

void randomChump(std::string name);
Zombie *newZombie(std::string name);
