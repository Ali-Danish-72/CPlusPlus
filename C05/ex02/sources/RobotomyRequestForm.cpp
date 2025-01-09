/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdanish <mdanish@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 21:52:07 by mdanish           #+#    #+#             */
/*   Updated: 2025/01/09 15:50:16 by mdanish          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/RobotomyRequestForm.hpp"
#include <cstdlib>

RobotomyRequestForm::RobotomyRequestForm(void) : AForm("Robotomy Request Form", 72, 45) {
	std::cout << "Default RobotomyRequestForm Constructor called.\n";
	this->_target = "default";
}

RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm("Robotomy Request Form", 72, 45) {
	std::cout << "Parametric RobotomyRequestForm Constructor called.\n";
	target == "" ? throw EmptyTarget() : this->_target = target;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm & other) : AForm("Robotomy Request Form", 72, 45) {
	std::cout << "Copy RobotomyRequestForm Constructor called.\n";
	*this = other;
}

RobotomyRequestForm::~RobotomyRequestForm(void) {
	std::cout << "RobotomyRequestForm Destructor called.\n";
}

RobotomyRequestForm & RobotomyRequestForm::operator = (const RobotomyRequestForm & other) {
	std::cout << "Copy RobotomyRequestForm Assignment Operator called.\n";
	if (this != & other) {
		this->_target = other._target;
		this->setSignStatus(other.getSignStatus());
	}
	return *this;
}

const char * RobotomyRequestForm::EmptyTarget::what(void) const throw() {
	return "The target prompted is empty.";
}

void RobotomyRequestForm::executeForm(void) const {
	srand(time(NULL));
	std::cout << "* DRILLINING NOISES *\n";
	std::cout << this->_target << (rand() % 2 ? " has been robotomised successfully.\n" : " could not be robotomised.\n");
}
