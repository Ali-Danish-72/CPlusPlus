/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdanish <mdanish@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 07:23:16 by mdanish           #+#    #+#             */
/*   Updated: 2024/12/24 22:38:10 by mdanish          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>

class Brain {
	private:
		std::string _ideas[100];

	public:
		Brain(void);
		Brain(const Brain & other);
		~Brain(void);
		Brain & operator = (const Brain & other);
		
		void addIdea(std::string idea, int index);
		std::string retrieveIdea(int index) const;
};
