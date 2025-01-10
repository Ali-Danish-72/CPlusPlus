/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdanish <mdanish@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 08:36:02 by mdanish           #+#    #+#             */
/*   Updated: 2025/01/09 15:49:47 by mdanish          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ShrubberyCreationForm.hpp"
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm(void) : AForm("Shrubbery Creation Form", 145, 137) {
	std::cout << "Default ShrubberyCreationForm Constructor called.\n";
	this->_target = "default";
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm("Shrubbery Creation Form", 145, 137) {
	std::cout << "Parametric ShrubberyCreationForm Constructor called.\n";
	target == "" ? throw EmptyTarget() : this->_target = target;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm & other) : AForm("Shrubbery Creation Form", 145, 137) {
	std::cout << "Copy ShrubberyCreationForm Constructor called.\n";
	*this = other;
}

ShrubberyCreationForm::~ShrubberyCreationForm(void) {
	std::cout << "ShrubberyCreationForm Destructor called.\n";
}

ShrubberyCreationForm & ShrubberyCreationForm::operator = (const ShrubberyCreationForm & other) {
	std::cout << "Copy ShrubberyCreationForm Assignment Operator called.\n";
	if (this != & other) {
		this->_target = other._target;
		this->setSignStatus(other.getSignStatus());
	}
	return *this;
}

const char * ShrubberyCreationForm::BadFile::what() const throw() {
	return "The file could not be opened.";
}

const char * ShrubberyCreationForm::EmptyTarget::what(void) const throw() {
	return "The target prompted is empty.";
}

void ShrubberyCreationForm::executeForm(void) const {
	std::ofstream outputFile((this->_target + "_shrubbery").c_str());
	if (outputFile.rdstate()) throw BadFile();

	outputFile	<< "        # #### ####\n"
				<< "      ### \\/#|### |/####\n"
				<< "     ##\\/#/ \\||/##/_/##/_#\n"
				<< "   ###  \\/###|/ \\/ # ###\n"
				<< " ##_\\_#\\_\\## | #/###_/_####\n"
				<< "## #### # \\ #| /  #### ##/##\n"
				<< " __#_--###`  |{,###---###-~\n"
				<< "           \\ }{\n"
				<< "            }}{\n"
				<< "            }}{\n"
				<< "       ejm  {{}\n"
				<< "      , -=-~{ .-^- _\n"
				<< "            `}\n"
				<< "             {\n";
	outputFile.close();
}
