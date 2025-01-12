/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Classes.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdanish <mdanish@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 09:04:43 by mdanish           #+#    #+#             */
/*   Updated: 2025/01/12 09:38:31 by mdanish          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Classes.hpp"
#include <cstdlib>
#include <iostream>
#include <ctime>

Base * generate(void) {
	srand(time(NULL));
	char c = rand() % 3;
	if (!c)
		return new A();
	if (c == 1)
		return new B();
	return new C();
}

void identify(Base * p) {
	dynamic_cast<A *>(p) ? std::cout << "This is a pointer to an object of class A\n" :
	dynamic_cast<B *>(p) ? std::cout << "This is a pointer to an object of class B\n" :
	dynamic_cast<C *>(p) ? std::cout << "This is a pointer to an object of class C\n" :
	std::cout << "This is pointer doesn't point to A, B or C\n";
}

void identify(Base & p) {
	dynamic_cast<A *>(&p) ? std::cout << "This is a reference to an object of class A\n" :
	dynamic_cast<B *>(&p) ? std::cout << "This is a reference to an object of class B\n" :
	dynamic_cast<C *>(&p) ? std::cout << "This is a reference to an object of class C\n" :
	std::cout << "This is reference doesn't point to A, B or C\n";
	
}
