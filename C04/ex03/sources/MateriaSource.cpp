/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdanish <mdanish@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/25 21:45:50 by mdanish           #+#    #+#             */
/*   Updated: 2024/12/26 23:03:19 by mdanish          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/MateriaSource.hpp"
#include <iostream>

MateriaSource::MateriaSource(void) {
	std::cout << "Default MateriaSource Constructor called.\n";
	for (int i = 0; i < 4; i++)
		this->_materials[i] = NULL;
}

MateriaSource::MateriaSource(MateriaSource const & other) {
	std::cout << "Copy MateriaSource Constructor called.\n";
	*this = other;
}

MateriaSource::~MateriaSource(void) {
	std::cout << "Destructor MateriaSource called.\n";
	for (int i = 0; i < 4; i++)
		delete this->_materials[i];
}

MateriaSource & MateriaSource::operator = (MateriaSource const & other) {
	if (this != &other) {
		for (int i = 0; i < 4; i++) {
			delete this->_materials[i];
			this->_materials[i] = other._materials[i]->clone();
			if (!this->_materials[i])
				std::cerr << "Cloning has failed\n";
		}
	}
	return *this;
}

void MateriaSource::learnMateria(AMateria * material) {
	for (int i = 0; i < 4; i++)
		if (!this->_materials[i])
			return (void)(this->_materials[i] = material);
	delete material;
}

AMateria * MateriaSource::createMateria(std::string const & type) {
	for (int i = 0; i < 4; i++)
		if (this->_materials[i]->getType() == type)
			return this->_materials[i]->clone();
	return NULL;
}
