/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdanish <mdanish@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/25 19:36:55 by mdanish           #+#    #+#             */
/*   Updated: 2024/12/25 23:23:44 by mdanish          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "ICharacter.hpp"

class Character : public ICharacter {
	private:
		std::string const & _name;
		AMateria *_materials[4];
		AMateria *_dropped[500];
		int _droppedCount;

	public:
		Character(std::string const & name);
		Character(Character const & other);
		~Character(void);
		Character & operator = (Character const & other);

		std::string const & getName() const;
		void equip(AMateria * m);
		void unequip(int idx);
		void use(int idx, ICharacter & target);
};
