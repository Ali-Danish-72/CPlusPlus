/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdanish <mdanish@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 14:14:27 by mdanish           #+#    #+#             */
/*   Updated: 2024/11/24 16:31:08 by mdanish          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Zombie.hpp"

int main() {
	Zombie *zombie;
	zombie = newZombie("SSSHHHHHHHH ;D");
	randomChump("randumfwefm wevovweev w w");
	zombie->announce();
	delete zombie;
	return 0;
}
