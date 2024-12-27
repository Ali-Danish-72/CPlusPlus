/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdanish <mdanish@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/22 23:12:49 by mdanish           #+#    #+#             */
/*   Updated: 2024/12/27 15:29:25 by mdanish          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public Animal {
	private:
		Brain * _brain;

	public:
		Dog(void);
		Dog(const Dog & other);
		~Dog(void);
		Dog & operator = (const Dog & other);

		void makeSound(void) const;
		void addIdea(std::string idea);
		std::string retrieveIdea(int index) const;
};
