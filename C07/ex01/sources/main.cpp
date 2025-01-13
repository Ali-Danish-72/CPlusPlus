/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdanish <mdanish@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 20:59:02 by mdanish           #+#    #+#             */
/*   Updated: 2025/01/13 21:28:31 by mdanish          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/iter.hpp"
#include <string>

int main( void ) {
	std::string a[10] = {"50", "10", "21", "38", "42", "55", "76", "27", "38", "95"};
	int b[10] = {50, 10, 21, 38, 42, 55, 76, 27, 38, 95};

	std::cout << "Called the instantiated printing template function:\n";
	::iter(a, 10, ::testprint<std::string>);
	std::cout << "Called the printing template function:\n";
	::iter(b, 10, ::testprint);
	return 0;
}
