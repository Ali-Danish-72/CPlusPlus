/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdanish <mdanish@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 16:27:27 by mdanish           #+#    #+#             */
/*   Updated: 2024/11/24 16:36:50 by mdanish          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Zombie.hpp"

int main() {
	Zombie *zombies = zombieHorde(5, "Clones");

	for (int index = 0; index < 5; index++)
		std::cout << index << " ", zombies[index].announce();
	delete[] zombies;
	return 0;
}
