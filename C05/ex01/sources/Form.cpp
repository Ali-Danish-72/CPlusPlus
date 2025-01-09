/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdanish <mdanish@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 17:24:04 by mdanish           #+#    #+#             */
/*   Updated: 2025/01/08 16:09:26 by mdanish          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Form.hpp"

Form::Form(void) : _formName("Basic Form"), _signGrade(150), _executeGrade(150) {
	std::cout << "Default Form Constructor called.\n";
	this->_signed = false;
}

Form::Form(std::string formName, int signGrade, int executeGrade) : _formName(formName), _signGrade(signGrade), _executeGrade(executeGrade) {
	std::cout << "Parametric Form Constructor called.\n";
	if (signGrade > 150 || executeGrade > 150)
		throw GradeTooLow();
	if (signGrade < 1 || executeGrade < 1)
		throw GradeTooHigh();
	formName == "" ? throw EmptyName() : this->_signed = false;
}

Form::Form(const Form & other) : _formName(other._formName + " copy"), _signGrade(other._signGrade), _executeGrade(other._executeGrade) {
	std::cout << "Copy Form Constructor called.\n";
	*this = other;
}

Form::~Form(void) {
	std::cout << "Form Destructor called.\n";
}

Form & Form::operator = (const Form & other) {
	std::cout << "Copy Form Assignment Operator called.\n";
	if (this != &other)
		this->_signed = other.getSignStatus();
	return *this;
}

const char * Form::GradeTooHigh::what(void) const throw() {
	return "Grade prompted is too high.";
}

const char * Form::GradeTooLow::what(void) const throw() {
	return "Grade prompted is too low.";
}

const char * Form::FormAlreadySigned::what(void) const throw() {
	return "The form is already signed.";
}

const char * Form::EmptyName::what(void) const throw() {
	return "The form name prompted is empty.";
}

bool Form::getSignStatus(void) const {
	return this->_signed;
}

int Form::getExecuteGrade(void) const {
	return this->_executeGrade;
}

int Form::getSignGrade(void) const {
	return this->_signGrade;
}

const std::string Form::getFormName(void) const {
	return this->_formName;
}

void Form::beSigned(const Bureaucrat & bureaucrat) {
	bureaucrat.getGrade() > this->getSignGrade() ? throw GradeTooLow() : 
		this->_signed ? throw FormAlreadySigned() : this->_signed = true;
}

std::ostream & operator << (std::ostream & out, const Form & other) {
	out << "Form \"" << other.getFormName() << "\", ";
	out << (other.getSignStatus() ? "is signed.\n" : "is not signed.\n");
	out << "It can be signed by grades above and equal to " << other.getSignGrade();
	out << " and can be executed by grades equal and above " << other.getExecuteGrade() << ".\n";
	return out;
}
