/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdanish <mdanish@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/25 21:40:16 by mdanish           #+#    #+#             */
/*   Updated: 2024/12/25 23:23:38 by mdanish          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource {
	private:
		AMateria * _materials[4];

	public:
		MateriaSource(void);
		MateriaSource(MateriaSource const & other);
		~MateriaSource(void);
		MateriaSource & operator = (MateriaSource const & other);

		void learnMateria(AMateria * material);
		AMateria * createMateria(std::string const & type);
};
