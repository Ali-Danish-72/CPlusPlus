/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdanish <mdanish@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/01 15:16:21 by mdanish           #+#    #+#             */
/*   Updated: 2025/01/07 08:20:37 by mdanish          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Bureaucrat.hpp"

int main(void) {
	try {
		Bureaucrat bob;
		Bureaucrat rob("Rob", 4);
		Bureaucrat tom("Tom", 40);
		Form a;
		Form b("b", 3, 15);

		std::cout << bob;
		std::cout << rob;
		std::cout << tom;
		std::cout << a;
		std::cout << b;
		tom.signForm(a);
		tom.signForm(b);
		std::cout << a;
		std::cout << b;
		tom = rob;
		std::cout << tom;
		a = b;
		std::cout << a;
	} catch (std::exception & exception) {
		std::cout << "Initialising the variables failed due to: " << exception.what() << "\n";
	}
	try {
		Bureaucrat rob("Rob", 1);
		Bureaucrat tom("Tom", 150);
		Form bill("New Law Bill", 5, 13);

		std::cout << rob;
		std::cout << tom;
		tom.signForm(bill);
		std::cout << bill;
		rob.signForm(bill);
		std::cout << bill;
		rob.signForm(bill);
		std::cout << bill;
	} catch (std::exception & exception) {
		std::cout << "Grade change failed due to: " << exception.what() << "\n";
	}
}
