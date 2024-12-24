/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdanish <mdanish@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/22 23:21:17 by mdanish           #+#    #+#             */
/*   Updated: 2024/12/24 22:41:28 by mdanish          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Brain.hpp"

class WrongAnimal {
	protected:
		std::string _type;
		Brain * _brain;

	public:
		WrongAnimal(void);
		WrongAnimal(std::string type);
		WrongAnimal(const WrongAnimal & other);
		virtual ~WrongAnimal(void);
		WrongAnimal & operator = (const WrongAnimal & other);

		void makeSound(void) const;
		const std::string & getType(void) const;
		void addIdea(std::string idea);
		std::string retrieveIdea(int index) const;
};
