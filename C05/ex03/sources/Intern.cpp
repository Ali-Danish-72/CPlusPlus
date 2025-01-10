/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdanish <mdanish@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 16:15:28 by mdanish           #+#    #+#             */
/*   Updated: 2025/01/10 04:50:35 by mdanish          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Intern.hpp"

Intern::Intern(void) {
	std::cout << "Default Intern Constructor called.\n";
}

Intern::Intern(const Intern & other) {
	std::cout << "Copy Intern Constructor called.\n";
	(void)other;
}

Intern::~Intern(void) {
	std::cout << "Intern Destructor called.\n";
}

Intern & Intern::operator = (const Intern & other) {
	std::cout << "Copy Intern Assignment Operator called.\n";
	(void)other;
	return (*this);
}

AForm * createShrubbery(std::string target) {
	std::cout << "Intern creates a Shrubbery Creation Form.\n";
	return new ShrubberyCreationForm(target);
}

AForm * createRobotomy(std::string target) {
	std::cout << "Intern creates a Robotomy Request Form.\n";
	return new RobotomyRequestForm(target);
}

AForm * createPresidential(std::string target) {
	std::cout << "Intern creates a Presidential Pardon Form.\n";
	return new PresidentialPardonForm(target);
}

const char * Intern::FormCreationFailed::what() const throw(){
	return "The allocation for the form failed.";
}

AForm * Intern::makeForm(std::string formType, std::string formTarget) const {
	std::string formTypes[] = {"Shrubbery Creation", "Robotomy Request", "Presedential Pardon"};
	AForm * (*formCreatorFunctions[3])(std::string target);
	formCreatorFunctions[0] = &createShrubbery;
	formCreatorFunctions[1] = &createRobotomy;
	formCreatorFunctions[2] = &createPresidential;

	for (int i = 0; i < 3; i++)
		if (formTypes[i] == formType)
			return formCreatorFunctions[i](formTarget);

	std::cout << "The form type \"" << formType << "\" doesn't exist.\n";

	return NULL;
}
