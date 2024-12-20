/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdanish <mdanish@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 15:31:37 by mdanish           #+#    #+#             */
/*   Updated: 2024/12/20 21:54:02 by mdanish          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/DiamondTrap.hpp"

int main(void) {
	DiamondTrap Monster("Monster");

	std::cout << Monster;
	Monster.attack("Fernando");
	Monster.highFivesGuys();
	Monster.whoAmI();
	std::cout << Monster;
	Monster.beRepaired(1);
	std::cout << Monster;
	Monster.guardGate();
	Monster.highFivesGuys();
	Monster.takeDamage(1);
	std::cout << Monster;
	return 0;
}
