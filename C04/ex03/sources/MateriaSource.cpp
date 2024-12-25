/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdanish <mdanish@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/25 21:45:50 by mdanish           #+#    #+#             */
/*   Updated: 2024/12/25 23:26:07 by mdanish          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/MateriaSource.hpp"
#include "../includes/Ice.hpp"
#include "../includes/Cure.hpp"
#include <iostream>

MateriaSource::MateriaSource(void) {
	std::cout << "Default MateriaSource Constructor called.\n";
	this->_materials[0] = NULL;
	this->_materials[1] = NULL;
	this->_materials[2] = NULL;
	this->_materials[3] = NULL;
}

MateriaSource::MateriaSource(MateriaSource const & other) {
	std::cout << "Copy MateriaSource Constructor called.\n";
	*this = other;
}

MateriaSource::~MateriaSource(void) {
	std::cout << "Destructor MateriaSource called.\n";
	delete this->_materials[0];
	delete this->_materials[1];
	delete this->_materials[2];
	delete this->_materials[3];
}

AMateria * typeBasedAllocation(AMateria * material) {
	if (!material)
		return NULL;
	AMateria * clone;
	if (material->getType() == "ice")
		clone = new Ice(* static_cast<Ice *>(material));
	else
		clone = new Cure(* static_cast<Cure *>(material));
	if (!clone)
		std::cerr << "Cloning has failed\n";
	return clone;
}

MateriaSource & MateriaSource::operator = (MateriaSource const & other) {
	if (this != &other) {
		delete this->_materials[0];
		this->_materials[0] = typeBasedAllocation(other._materials[0]);
		delete this->_materials[1];
		this->_materials[1] = typeBasedAllocation(other._materials[1]);
		delete this->_materials[2];
		this->_materials[2] = typeBasedAllocation(other._materials[2]);
		delete this->_materials[3];
		this->_materials[3] = typeBasedAllocation(other._materials[3]);
	}
	return *this;
}

void MateriaSource::learnMateria(AMateria * material) {
	for (int i = 0; i < 4; i++)
		if (!this->_materials[i]) {
			this->_materials[i] = material;
			break ;
		}
}

AMateria * MateriaSource::createMateria(std::string const & type) {
	for (int i = 0; i < 4; i++)
		if (this->_materials[i]->getType() == type)
			return typeBasedAllocation(this->_materials[i]);
	return NULL;
}
