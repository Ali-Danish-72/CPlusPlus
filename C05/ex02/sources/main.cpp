/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdanish <mdanish@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/01 15:16:21 by mdanish           #+#    #+#             */
/*   Updated: 2025/01/09 16:08:07 by mdanish          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ShrubberyCreationForm.hpp"
#include "../includes/PresidentialPardonForm.hpp"
#include "../includes/RobotomyRequestForm.hpp"

void testShrubbery() {
	try {
		Bureaucrat				bob("Bob", 146);
		// Bureaucrat				bob("Bob", 138);
		ShrubberyCreationForm   formA("Town_Square");

		std::cout << formA;
		bob.signForm(formA);
		std::cout << formA;

		std::cout << bob;
		bob.incrementGrade();
		std::cout << bob;

		bob.signForm(formA);
		bob.executeForm(formA);

		std::cout << formA;

	} catch (std::exception &e) {
		std::cout << e.what();
	}
}

void testRobotomy() {
	try {
		Bureaucrat				bob("Bob", 73);
		// Bureaucrat				bob("Bob", 46);
		RobotomyRequestForm		formB("Space Shuttle");

		std::cout << formB;
		bob.signForm(formB);
		std::cout << formB;

		std::cout << bob;
		bob.incrementGrade();
		std::cout << bob;

		bob.signForm(formB);
		bob.executeForm(formB);

		std::cout << formB;
	} catch (std::exception &e) {
		std::cout << e.what();
	}
}

void testPresidential() {
	  try {
		// Bureaucrat				bob("Bob", 26);
		Bureaucrat				bob("Bob", 6);
		PresidentialPardonForm	formC("Optimus Prime");

		std::cout << formC;
		bob.signForm(formC);
		std::cout << formC;

		std::cout << bob;
		bob.incrementGrade();
		std::cout << bob;

		bob.signForm(formC);
		bob.executeForm(formC);

		std::cout << formC;
	} catch (std::exception &e) {
		std::cout << e.what();
	}
}

int main(void) {
	int testCase = 1;

	if (testCase == 1) testShrubbery();
	else if (testCase == 2) testRobotomy();
	else testPresidential();
	return 0;
}
