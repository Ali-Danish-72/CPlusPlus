/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdanish <mdanish@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/25 16:48:22 by mdanish           #+#    #+#             */
/*   Updated: 2024/12/26 22:54:17 by mdanish          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>
#include "ICharacter.hpp"

class ICharacter;

class AMateria {
	protected:
		std::string _type;

	public:
		AMateria(void);
		AMateria(std::string const & type);
		AMateria(AMateria const & other);
		virtual ~AMateria(void);
		AMateria & operator = (AMateria const & other);

		std::string const & getType(void) const;
		virtual AMateria * clone(void) const = 0;
		virtual void use(ICharacter & target);
};
