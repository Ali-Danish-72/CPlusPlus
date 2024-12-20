/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdanish <mdanish@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 15:31:37 by mdanish           #+#    #+#             */
/*   Updated: 2024/12/20 22:11:44 by mdanish          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ClapTrap.hpp"

int main(void) {
	ClapTrap bob("bob");
	ClapTrap rob = ClapTrap("rob");

	std::cout << bob;
	std::cout << rob;
	rob.attack("bob");
	bob.takeDamage(rob.getAttackDamage());
	std::cout << bob;
	std::cout << rob;
	bob.attack("rob");
	rob.takeDamage(bob.getAttackDamage());
	std::cout << bob;
	std::cout << rob;
	bob.beRepaired(3);
	rob.beRepaired(3);
	std::cout << bob;
	std::cout << rob;
	return 0;
}
