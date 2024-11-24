/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdanish <mdanish@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 11:25:11 by mdanish           #+#    #+#             */
/*   Updated: 2024/11/24 18:01:58 by mdanish          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Zombie.hpp"

Zombie::Zombie(std::string name) {
	this->_name = name;
	return;
}

Zombie::Zombie(void) {
	return;
}

Zombie::~Zombie(void) {
	std::cerr << this->_name << std::endl;
	return;
}

void Zombie::announce(void) {
	std::cout << this->_name << ": BraiiiiiiinnnzzzZ...\n";
}

void Zombie::setName(std::string name) {
	this->_name = name;
}
