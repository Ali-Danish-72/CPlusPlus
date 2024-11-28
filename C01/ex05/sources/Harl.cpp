/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdanish <mdanish@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 15:00:26 by mdanish           #+#    #+#             */
/*   Updated: 2024/11/28 19:14:43 by mdanish          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "../includes/Harl.hpp"

Harl::Harl(void) {
	return;
}

Harl::~Harl(void) {
	return;
}

void Harl::debug(void) {
	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do!\n";
}

void Harl::info(void) {
	std::cout << "I cannot believe adding extra bacon costs more money. You didn't put enough bacon in my burger! If you did, I wouldn't be asking for more!\n";
}

void Harl::warning(void) {
	std::cout << "I think I deserve to have some extra bacon for free. I've been coming for years whereas you started working here since last month.\n";
}

void Harl::error(void) {
	std::cout << "This is unacceptable! I want to speak to the manager now.\n";
}

void Harl::complain(std::string level) {
	std::string levels[] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	void (Harl::*level_functions[4])();
	level_functions[0] = &Harl::debug;
	level_functions[1] = &Harl::info;
	level_functions[2] = &Harl::warning;
	level_functions[3] = &Harl::error;

	for (int i = 0; i < 4; i++) {
		if (levels[i] == level)
			return (this->*level_functions[i])();
	}
	
}

