/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdanish <mdanish@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 06:57:25 by mdanish           #+#    #+#             */
/*   Updated: 2024/12/27 15:30:54 by mdanish          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "WrongAnimal.hpp"
#include "Brain.hpp"

class WrongCat : public WrongAnimal {
	private:
		Brain * _brain;

	public:
		WrongCat(void);
		WrongCat(const WrongCat & other);
		~WrongCat(void);
		WrongCat & operator = (const WrongCat & other);

		void makeSound(void) const;
		void addIdea(std::string idea);
		std::string retrieveIdea(int index) const;
};
