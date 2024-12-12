/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdanish <mdanish@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 15:31:37 by mdanish           #+#    #+#             */
/*   Updated: 2024/12/12 15:41:26 by mdanish          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ClapTrap.hpp"

int main(void) {
	ClapTrap bob("bob");
	ClapTrap rob = ClapTrap("rob");

	bob.status();
	rob.status();
	rob.attack("bob");
	bob.takeDamage(rob.getAttackDamage());
	bob.status();
	rob.status();
	bob.attack("rob");
	rob.takeDamage(bob.getAttackDamage());
	bob.status();
	rob.status();
	bob.beRepaired(3);
	rob.beRepaired(3);
	bob.status();
	rob.status();
	return 0;
}
