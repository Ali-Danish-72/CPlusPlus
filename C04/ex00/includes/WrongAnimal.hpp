/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdanish <mdanish@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/22 23:21:17 by mdanish           #+#    #+#             */
/*   Updated: 2024/12/23 07:14:59 by mdanish          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>

class WrongAnimal {
	protected:
		std::string _type;

	public:
		WrongAnimal(void);
		WrongAnimal(std::string type);
		WrongAnimal(const WrongAnimal & other);
		virtual ~WrongAnimal(void);
		WrongAnimal & operator = (const WrongAnimal & other);

		void makeSound(void) const;
		const std::string & getType(void) const;
};
