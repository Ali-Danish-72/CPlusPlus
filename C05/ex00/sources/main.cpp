/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdanish <mdanish@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/01 15:16:21 by mdanish           #+#    #+#             */
/*   Updated: 2025/01/06 00:25:28 by mdanish          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Bureaucrat.hpp"

int main(void) {
	try {
		Bureaucrat bob;
		Bureaucrat rob("Rob", 4);
		Bureaucrat tom("Tom", 40);

		std::cout << bob;
		std::cout << rob;
		std::cout << tom;

		tom = rob;
		std::cout << tom;
	} catch (std::exception & exception) {
		std::cout << "Initialising the variables failed due to: " << exception.what() << "\n";
		return 0;
	}
	try {
		Bureaucrat rob("Rob", 1);
		Bureaucrat tom("Tom", 150);

		std::cout << rob;
		std::cout << tom;
		rob.incrementGrade();
		std::cout << rob;
		std::cout << tom;
		tom.decrementGrade();
		std::cout << rob;
		std::cout << tom;
	} catch (std::exception & exception) {
		std::cout << "Grade change failed due to: " << exception.what() << "\n";
		return 0;
	}
}
