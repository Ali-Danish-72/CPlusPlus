/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdanish <mdanish@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 08:38:30 by mdanish           #+#    #+#             */
/*   Updated: 2025/01/12 08:56:35 by mdanish          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Serializer.hpp"
#include <iostream>

int main() {
	Data data = {0, 'a'};

	uintptr_t rawStorage;
	
	rawStorage = Serializer::serialize(&data);
	std::cout << "The serialized structure pointer: 0x" << std::hex << rawStorage << ".\n";
	std::cout << "The original structure pointer: " << &data << ".\n";
	std::cout << "The index of data: " << Serializer::deserialize(rawStorage)->index << ".\n";
	std::cout << "The tag of data: " << Serializer::deserialize(rawStorage)->tag << ".\n";
	return 0;
}
