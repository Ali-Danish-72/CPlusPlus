/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdanish <mdanish@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 03:20:33 by mdanish           #+#    #+#             */
/*   Updated: 2025/01/12 04:49:29 by mdanish          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Converter.hpp"

int main(int ac, char **av) {
	if (ac != 2){
		std::cout << "Use as follows:\n./convert [value]\n";
		return 0;
	}
	ScalarConverter::convert(av[1]);
	return 0;
}
