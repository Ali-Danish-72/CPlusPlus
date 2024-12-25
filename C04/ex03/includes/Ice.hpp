/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdanish <mdanish@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/25 18:25:38 by mdanish           #+#    #+#             */
/*   Updated: 2024/12/25 19:51:42 by mdanish          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "AMateria.hpp"

class Ice : public AMateria {
	public:
		Ice(void);
		Ice(Ice const & other);
		~Ice(void);
		Ice & operator = (Ice const & other);

		AMateria * clone(void) const;
		void use(ICharacter & target);
};
