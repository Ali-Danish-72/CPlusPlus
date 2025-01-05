/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdanish <mdanish@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/01 14:57:42 by mdanish           #+#    #+#             */
/*   Updated: 2025/01/06 00:24:28 by mdanish          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Bureaucrat.hpp"

Bureaucrat::Bureaucrat(void) : _name("Default"), _grade(150) {
	std::cout << "Default Bureaucrat Constructor called.\n";
}

Bureaucrat::Bureaucrat(const std::string name, short int grade) : _name(name) {
	std::cout << "Parametric Bureaucrat Constructor called.\n";
	if (grade > 150)
		throw GradeTooHigh();
	if (grade < 1)
		throw GradeTooLow();
	this->_grade = grade;
}

Bureaucrat::Bureaucrat(const Bureaucrat & other) : _name(other.getName() + " copy") {
	std::cout << "Copy Bureaucrat Constructor called.\n";
	*this = other;
}

Bureaucrat::~Bureaucrat(void) {
	std::cout << "Bureaucrat Destructor called.\n";
}

Bureaucrat & Bureaucrat::operator = (const Bureaucrat & other) {
	std::cout << "Copy Bureaucrat Assignment Operator called.\n";
	if (this != &other)
		this->_grade = other._grade;
	return *this;
}


const char * Bureaucrat::GradeTooHigh::what(void) const throw() {
	return "Grade prompted is too high.";
}

const char * Bureaucrat::GradeTooLow::what(void) const throw() {
	return "Grade prompted is too low.";
}

const std::string & Bureaucrat::getName(void) const {
	return this->_name;
}

short int Bureaucrat::getGrade(void) const {
	return this->_grade;
}

void Bureaucrat::incrementGrade(void) {
	this->_grade == 1 ? throw GradeTooHigh() : this->_grade--;
}

void Bureaucrat::decrementGrade(void) {
	this->_grade == 150 ? throw GradeTooLow() : this->_grade++;
}

std::ostream & operator << (std::ostream & out, const Bureaucrat & other) {
	out << other.getName() << ", bureaucrat grade " << other.getGrade() << ".\n";
	return out;
}
