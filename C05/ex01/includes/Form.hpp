/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdanish <mdanish@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 02:59:09 by mdanish           #+#    #+#             */
/*   Updated: 2025/01/07 08:03:47 by mdanish          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Bureaucrat.hpp"

class Bureaucrat;

class Form {
	private:
		bool _signed;
		const std::string _formName;
		const int _signGrade;
		const int _executeGrade;

	public:
		Form(void);
		Form(std::string name, int signGrade, int executeGrade);
		Form(const Form & other);
		~Form(void);
		Form & operator = (const Form & other);

		class GradeTooLow : public std::exception {
			public:
				const char * what() const throw();
		};
		class GradeTooHigh : public std::exception {
			public:
				const char * what() const throw();
		};
		class FormAlreadySigned : public std::exception {
			public:
				const char * what() const throw();
		};

		bool getSignStatus(void) const;
		int getExecuteGrade(void) const;
		int getSignGrade(void) const;
		const std::string getFormName(void) const;

		void beSigned(const Bureaucrat & bureaucrat);
};

std::ostream & operator << (std::ostream & out, const Form & other);
