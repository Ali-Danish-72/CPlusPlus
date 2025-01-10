/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdanish <mdanish@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 10:47:51 by mdanish           #+#    #+#             */
/*   Updated: 2025/01/09 15:49:32 by mdanish          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(void) : AForm("Presidential Pardon Form", 25, 5) {
	std::cout << "Default PresidentialPardonForm Constructor called.\n";
	this->_target = "default";
}

PresidentialPardonForm::PresidentialPardonForm(std::string target) : AForm("Presidential Pardon Form", 25, 5) {
	std::cout << "Parametric PresidentialPardonForm Constructor called.\n";
	target == "" ? throw EmptyTarget() : this->_target = target;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm & other) : AForm("Presidential Pardon Form", 25, 5) {
	std::cout << "Copy PresidentialPardonForm Constructor called.\n";
	*this = other;
}

PresidentialPardonForm::~PresidentialPardonForm(void) {
	std::cout << "PresidentialPardonForm Destructor called.\n";
}

PresidentialPardonForm & PresidentialPardonForm::operator = (const PresidentialPardonForm & other) {
	std::cout << "Copy PresidentialPardonForm Assignment Operator called.\n";
	if (this != & other) {
		this->_target = other._target;
		this->setSignStatus(other.getSignStatus());
	}
	return *this;
}

const char * PresidentialPardonForm::EmptyTarget::what(void) const throw() {
	return "The target prompted is empty.";
}

void PresidentialPardonForm::executeForm(void) const {
	std::cout << this->_target << " has been pardoned by Zaphoid Beeblebrox.\n";
}
