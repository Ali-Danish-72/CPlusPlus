/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ICharacter.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdanish <mdanish@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/25 19:24:50 by mdanish           #+#    #+#             */
/*   Updated: 2024/12/25 19:51:53 by mdanish          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

class ICharacter; // test removal

#include "AMateria.hpp"

class ICharacter
{
	public:
		virtual ~ICharacter() {};
		virtual std::string const & getName() const = 0;
		virtual void equip(AMateria * m) = 0;
		virtual void unequip(int idx) = 0;
		virtual void use(int idx, ICharacter & target) = 0;
};
