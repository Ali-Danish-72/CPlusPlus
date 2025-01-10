/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdanish <mdanish@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 16:11:33 by mdanish           #+#    #+#             */
/*   Updated: 2025/01/10 04:48:37 by mdanish          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "../includes/ShrubberyCreationForm.hpp"
#include "../includes/PresidentialPardonForm.hpp"
#include "../includes/RobotomyRequestForm.hpp"

class Intern {
	public:
		Intern(void);
		Intern(const Intern & other);
		~Intern(void);
		Intern & operator = (const Intern & other);

		class FormCreationFailed : public std::exception {
			const char * what() const throw();
		};

		AForm * makeForm(std::string formType, std::string formTarget) const;
};
