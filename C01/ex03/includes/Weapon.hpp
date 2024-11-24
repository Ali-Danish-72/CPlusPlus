/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdanish <mdanish@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 17:14:17 by mdanish           #+#    #+#             */
/*   Updated: 2024/11/24 18:40:20 by mdanish          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>

class Weapon {
	private:
		std::string _type;
		Weapon(void);

	public:
		Weapon(std::string type);
		~Weapon(void);
		std::string const getType(void) const;
		void setType(std::string type);
};
