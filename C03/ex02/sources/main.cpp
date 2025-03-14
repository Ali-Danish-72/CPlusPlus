/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdanish <mdanish@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 15:31:37 by mdanish           #+#    #+#             */
/*   Updated: 2024/12/20 21:36:20 by mdanish          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/FragTrap.hpp"

int main(void) {
	ClapTrap bob("bob");
	FragTrap rob("rob");

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
	rob.highFivesGuys();
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
