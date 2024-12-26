/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdanish <mdanish@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/25 19:36:55 by mdanish           #+#    #+#             */
/*   Updated: 2024/12/26 20:24:15 by mdanish          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "ICharacter.hpp"

class Character : public ICharacter {
	private:
		std::string const _name;
		AMateria * _materials[4];
		bool _available[4];

	public:
		Character(void);
		Character(std::string const name);
		Character(Character const & other);
		~Character(void);
		Character & operator = (Character const & other);

		std::string const & getName() const;
		void equip(AMateria * m);
		void unequip(int idx);
		void use(int idx, ICharacter & target);
};
