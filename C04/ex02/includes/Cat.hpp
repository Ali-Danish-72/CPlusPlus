/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdanish <mdanish@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/22 23:04:34 by mdanish           #+#    #+#             */
/*   Updated: 2024/12/27 15:28:25 by mdanish          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Animal.hpp"
#include "Brain.hpp"

class Cat : public Animal {
	private:
		Brain * _brain;

	public:
		Cat(void);
		Cat(const Cat & other);
		~Cat(void);
		Cat & operator = (const Cat & other);

		void makeSound(void) const;
		void addIdea(std::string idea);
		std::string retrieveIdea(int index) const;
};
