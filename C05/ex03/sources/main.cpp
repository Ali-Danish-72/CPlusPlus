/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdanish <mdanish@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/01 15:16:21 by mdanish           #+#    #+#             */
/*   Updated: 2025/01/10 17:09:22 by mdanish          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Intern.hpp"

void testShrubbery() {
	AForm * form;
	try {
		Bureaucrat				bob("Bob", 146);
		// Bureaucrat				bob("Bob", 138);
		Intern					freshie;
		form = freshie.makeForm("Shrubbery Creation", "Town_Square");
		if (!form) throw Intern::FormCreationFailed();

		std::cout << form;
		bob.signForm(*form);
		std::cout << form;

		std::cout << bob;
		bob.incrementGrade();
		std::cout << bob;

		bob.signForm(*form);
		bob.executeForm(*form);

		std::cout << form;
	} catch (std::exception &e) {
		std::cout << e.what() << '\n';
	}
	delete form;
}

void testRobotomy() {
	AForm * form;
	try {
		Bureaucrat				bob("Bob", 73);
		// Bureaucrat				bob("Bob", 46);
		Intern					freshie;
		form = freshie.makeForm("Robotomy Request", "Space Shuttle");
		if (!form) throw Intern::FormCreationFailed();

		std::cout << form;
		bob.signForm(*form);
		std::cout << form;

		std::cout << bob;
		bob.incrementGrade();
		std::cout << bob;

		bob.signForm(*form);
		bob.executeForm(*form);

		std::cout << form;
	} catch (std::exception &e) {
		std::cout << e.what() << '\n';
	}
	delete form;
}

void testPresidential() {
	AForm * form;
	try {
		Bureaucrat				bob("Bob", 26);
		// Bureaucrat				bob("Bob", 6);
		Intern					freshie;
		form = freshie.makeForm("Presidential Pardon", "Optimus Prime");
		if (!form) throw Intern::FormCreationFailed();

		std::cout << form;
		bob.signForm(*form);
		std::cout << form;

		std::cout << bob;
		bob.incrementGrade();
		std::cout << bob;

		bob.signForm(*form);
		bob.executeForm(*form);

		std::cout << form;
	} catch (std::exception &e) {
		std::cout << e.what() << '\n';
	}
	delete form;
}

int main(void) {
	int testCase = 1;

	if (testCase == 1) testShrubbery();
	else if (testCase == 2) testRobotomy();
	else testPresidential();
	try {
		Intern newbie;
		AForm * noForm = newbie.makeForm("non existant", "no one");
		if (!noForm) throw Intern::FormCreationFailed();
	} catch (std::exception &e) {
		std::cout << e.what() << "\n";
	}
	return 0;
}
