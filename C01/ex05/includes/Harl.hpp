/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdanish <mdanish@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 14:53:22 by mdanish           #+#    #+#             */
/*   Updated: 2024/11/28 19:14:39 by mdanish          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>

class Harl {
	private:
		void debug(void);
		void info(void);
		void warning(void);
		void error(void);

	public:
		Harl(void);
		~Harl(void);

		void complain(std::string level);
};
