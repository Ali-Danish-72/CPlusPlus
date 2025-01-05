/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdanish <mdanish@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/31 19:38:03 by mdanish           #+#    #+#             */
/*   Updated: 2025/01/01 15:19:41 by mdanish          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <exception>
#include <iostream>
#include <string>

class Bureaucrat {
	private:
		const std::string _name;
		short int _grade;

	public:
		Bureaucrat(void);
		Bureaucrat(const std::string name, short int grade);
		Bureaucrat(const Bureaucrat & other);
		~Bureaucrat(void);
		Bureaucrat & operator = (const Bureaucrat & other);

		class GradeTooHigh : public std::exception {
			public:
				const char * what(void) const throw();
		};
		class GradeTooLow : public std::exception {
			public:
				const char * what(void) const throw();
		};

		const std::string & getName(void) const;
		short int getGrade(void) const;

		void incrementGrade(void);
		void decrementGrade(void);
};

std::ostream & operator << (std::ostream & out, const Bureaucrat & other);
