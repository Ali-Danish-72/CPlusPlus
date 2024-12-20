/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdanish <mdanish@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 15:31:37 by mdanish           #+#    #+#             */
/*   Updated: 2024/12/20 16:04:03 by mdanish          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ScavTrap.hpp"

int main(void) {
	ClapTrap bob("bob");
	ScavTrap rob("rob");

	std::cout << bob;
	std::cout << rob;
	rob.attack("bob");
	bob.takeDamage(rob.getAttackDamage());
	std::cout << bob;
	std::cout << rob;
	bob.attack("tom");
	rob.takeDamage(bob.getAttackDamage());
	std::cout << bob;
	std::cout << rob;
	rob.guardGate();
	bob.beRepaired(10);
	rob.beRepaired(10);
	std::cout << bob;
	std::cout << rob;
	rob.attack("bob");
	bob.takeDamage(rob.getAttackDamage());
	std::cout << bob;
	std::cout << rob;
	bob.attack("tom");
	rob.takeDamage(bob.getAttackDamage());
	std::cout << bob;
	std::cout << rob;
	return 0;
}
