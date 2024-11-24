/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdanish <mdanish@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 16:40:40 by mdanish           #+#    #+#             */
/*   Updated: 2024/11/24 17:09:16 by mdanish          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

int main() {
	std::string string = "HI THIS IS BRAIN";
	std::string *stringPTR = &string;
	std::string &stringREF = string;

	std::cout << "Memory Address of the sring variable: " << &string
	<< "\nMemory Address held by stringPTR:     " << &stringPTR
	<< "\nMemory Address held by stringREF:     " << &stringREF
	<< "\n\nValue of the sring variable:   " << string
	<< "\nValue pointed to by stringPTR: " << stringPTR
	<< "\nValue pointed to by stringREF: " << stringREF
	<< std::endl;

	// std::cout << "Memory Address of the sring variable: " << &string
	// << "\nMemory Address held by stringPTR:     " << stringPTR
	// << "\nMemory Address held by stringREF:     " << &stringREF
	// << "\n\nValue of the sring variable:   " << string
	// << "\nValue pointed to by stringPTR: " << *stringPTR
	// << "\nValue pointed to by stringREF: " << stringREF
	// << std::endl;
	
	return 0;
}
