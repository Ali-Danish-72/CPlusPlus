/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdanish <mdanish@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/25 19:17:05 by mdanish           #+#    #+#             */
/*   Updated: 2024/12/25 19:51:46 by mdanish          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "AMateria.hpp"

class Cure : public AMateria {
	public:
		Cure(void);
		Cure(Cure const & other);
		~Cure(void);
		Cure & operator = (Cure const & other);

		AMateria* clone(void) const;
		void use(ICharacter & target);
};
