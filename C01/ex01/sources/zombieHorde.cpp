/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdanish <mdanish@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 15:52:17 by mdanish           #+#    #+#             */
/*   Updated: 2024/11/24 16:37:06 by mdanish          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Zombie.hpp"

Zombie	*zombieHorde(int numberOfZombies, std::string name) {
	Zombie	*zombies = new Zombie[numberOfZombies];

	for (int index = 0; index < numberOfZombies; index++)
		zombies[index].setName(name);
	return zombies;
}
