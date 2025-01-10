/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdanish <mdanish@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 10:46:53 by mdanish           #+#    #+#             */
/*   Updated: 2025/01/09 15:48:56 by mdanish          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "AForm.hpp"

class PresidentialPardonForm : public AForm {
	private:
		std::string _target;

	public:
		PresidentialPardonForm(void);
		PresidentialPardonForm(std::string target);
		PresidentialPardonForm(const PresidentialPardonForm & other);
		~PresidentialPardonForm(void);
		PresidentialPardonForm & operator = (const PresidentialPardonForm & other);

		class EmptyTarget : public std::exception {
			public:
				const char * what() const throw();
		};

		void executeForm(void) const;
};
