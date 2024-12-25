/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdanish <mdanish@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/25 16:48:22 by mdanish           #+#    #+#             */
/*   Updated: 2024/12/25 22:35:28 by mdanish          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

class AMateria; // test removal

#include <string>
#include "ICharacter.hpp"

class AMateria {
	protected:
		const std::string _type;

	public:
		AMateria(std::string const & type);
		virtual ~AMateria(void);

		std::string const & getType(void) const;
		virtual AMateria * clone(void) const = 0;
		virtual void use(ICharacter & target);
};
