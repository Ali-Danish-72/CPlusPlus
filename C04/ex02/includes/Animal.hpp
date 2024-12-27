/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdanish <mdanish@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/22 19:17:48 by mdanish           #+#    #+#             */
/*   Updated: 2024/12/27 15:50:56 by mdanish          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>

class Animal {
	protected:
		std::string _type;

	public:
		Animal(void);
		Animal(std::string type);
		Animal(const Animal & other);
		virtual ~Animal(void);
		Animal & operator = (const Animal & other);

		virtual void makeSound(void) const = 0;
		const std::string & getType(void) const;
};
