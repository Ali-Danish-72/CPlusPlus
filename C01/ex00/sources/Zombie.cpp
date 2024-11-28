/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdanish <mdanish@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 11:25:11 by mdanish           #+#    #+#             */
/*   Updated: 2024/11/28 18:55:17 by mdanish          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "../includes/Zombie.hpp"

Zombie::Zombie(std::string name) : _name(name) {
	return;
}

Zombie::Zombie(void) {
	return;
}

Zombie::~Zombie(void) {
	std::cerr << "Destructing " << this->_name << std::endl;
	return;
}

void Zombie::announce(void) {
	std::cout << this->_name << ": BraiiiiiiinnnzzzZ...\n";
}
