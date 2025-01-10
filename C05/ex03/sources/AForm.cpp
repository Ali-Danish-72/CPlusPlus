/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdanish <mdanish@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 17:24:04 by mdanish           #+#    #+#             */
/*   Updated: 2025/01/09 17:04:12 by mdanish          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/AForm.hpp"

AForm::AForm(void) : _formName("Basic Form"), _signGrade(150), _executeGrade(150) {
	std::cout << "Default AForm Constructor called.\n";
	this->_signed = false;
}

AForm::AForm(std::string formName, int signGrade, int executeGrade) : _formName(formName), _signGrade(signGrade), _executeGrade(executeGrade) {
	std::cout << "Parametric AForm Constructor called.\n";
	if (signGrade > 150 || executeGrade > 150)
		throw GradeTooLow();
	if (signGrade < 1 || executeGrade < 1)
		throw GradeTooHigh();
	formName == "" ? throw EmptyName() : this->_signed = false;
}

AForm::AForm(const AForm & other) : _formName(other._formName + " copy"), _signGrade(other._signGrade), _executeGrade(other._executeGrade) {
	std::cout << "Copy AForm Constructor called.\n";
	*this = other;
}

AForm::~AForm(void) {
	std::cout << "AForm Destructor called.\n";
}

AForm & AForm::operator = (const AForm & other) {
	std::cout << "Copy AForm Assignment Operator called.\n";
	if (this != &other)
		this->_signed = other.getSignStatus();
	return *this;
}

const char * AForm::GradeTooHigh::what(void) const throw() {
	return "Grade prompted is too high.";
}

const char * AForm::GradeTooLow::what(void) const throw() {
	return "Grade prompted is too low.";
}

const char * AForm::FormAlreadySigned::what(void) const throw() {
	return "The form is already signed.";
}

const char * AForm::FormNotSigned::what(void) const throw() {
	return "The form is not signed.";
}

const char * AForm::EmptyName::what(void) const throw() {
	return "The form name prompted is empty.";
}

bool AForm::getSignStatus(void) const {
	return this->_signed;
}

int AForm::getExecuteGrade(void) const {
	return this->_executeGrade;
}

int AForm::getSignGrade(void) const {
	return this->_signGrade;
}

const std::string AForm::getFormName(void) const {
	return this->_formName;
}

void AForm::setSignStatus(bool status) {
	this->_signed = status;
}

void AForm::beSigned(const Bureaucrat & bureaucrat) {
	bureaucrat.getGrade() > this->getSignGrade() ? throw GradeTooLow() : 
		this->_signed ? throw FormAlreadySigned() : this->_signed = true;
}

void AForm::execute(const Bureaucrat & bureaucrat) const {
	if (!this->getSignStatus()) throw FormNotSigned();
	else if (bureaucrat.getGrade() > this->getExecuteGrade()) throw GradeTooLow();
	this->executeForm();
}

std::ostream & operator << (std::ostream & out, const AForm & other) {
	out << "Form \"" << other.getFormName() << "\", ";
	out << (other.getSignStatus() ? "is signed.\n" : "is not signed.\n");
	out << "It can be signed by grades above and equal to " << other.getSignGrade();
	out << " and can be executed by grades equal and above " << other.getExecuteGrade() << ".\n";
	return out;
}

std::ostream & operator << (std::ostream & out, const AForm * other) {
	out << "Form \"" << other->getFormName() << "\", ";
	out << (other->getSignStatus() ? "is signed.\n" : "is not signed.\n");
	out << "It can be signed by grades above and equal to " << other->getSignGrade();
	out << " and can be executed by grades equal and above " << other->getExecuteGrade() << ".\n";
	return out;
}
