/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdanish <mdanish@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 02:59:09 by mdanish           #+#    #+#             */
/*   Updated: 2025/01/09 17:03:42 by mdanish          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm {
	private:
		bool _signed;
		const std::string _formName;
		const int _signGrade;
		const int _executeGrade;

	public:
		AForm(void);
		AForm(std::string name, int signGrade, int executeGrade);
		AForm(const AForm & other);
		virtual ~AForm(void);
		AForm & operator = (const AForm & other);

		class GradeTooLow : public std::exception {
			public:
				const char * what() const throw();
		};
		class GradeTooHigh : public std::exception {
			public:
				const char * what() const throw();
		};
		class EmptyName : public std::exception {
			public:
				const char * what() const throw();
		};
		class FormAlreadySigned : public std::exception {
			public:
				const char * what() const throw();
		};
		class FormNotSigned : public std::exception {
			public:
				const char * what() const throw();
		};

		bool getSignStatus(void) const;
		int getExecuteGrade(void) const;
		int getSignGrade(void) const;
		const std::string getFormName(void) const;
		void setSignStatus(bool status);

		void beSigned(const Bureaucrat & bureaucrat);
		void execute(const Bureaucrat & bureaucrat) const;
		virtual void executeForm(void) const = 0;
};

std::ostream & operator << (std::ostream & out, const AForm & other);
std::ostream & operator << (std::ostream & out, const AForm * other);
