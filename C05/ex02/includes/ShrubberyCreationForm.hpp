/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdanish <mdanish@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 08:32:50 by mdanish           #+#    #+#             */
/*   Updated: 2025/01/09 15:49:15 by mdanish          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "AForm.hpp"

class ShrubberyCreationForm : public AForm {
	private:
		std::string _target;

	public:
		ShrubberyCreationForm(void);
		ShrubberyCreationForm(std::string target);
		ShrubberyCreationForm(const ShrubberyCreationForm & other);
		~ShrubberyCreationForm(void);
		ShrubberyCreationForm & operator = (const ShrubberyCreationForm & other);

		class BadFile : public std::exception {
			const char * what () const throw();
		};
		class EmptyTarget : public std::exception {
			public:
				const char * what() const throw();
		};

		void executeForm(void) const;
};
