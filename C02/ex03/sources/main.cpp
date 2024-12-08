/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdanish <mdanish@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 17:43:08 by mdanish           #+#    #+#             */
/*   Updated: 2024/12/08 20:59:01 by mdanish          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Point.hpp"

int main( void ) {
	std::cout << (bsp(Point(), Point(10.0, 30.0), Point(20.0, 0.0),
	Point(30.0, 15.0)) ? "Inside\n" : "Outside\n");
	std::cout << (bsp(Point(), Point(10.0, 30.0), Point(20.0, 0.0),
	Point(5.7, 10.20)) ? "Inside\n" : "Outside\n");
	std::cout << (bsp(Point(), Point(10.0, 30.0), Point(20.0, 0.0),
	Point(10.0, 30.0)) ? "Inside\n" : "Outside\n");
	std::cout << (bsp(Point(), Point(10.0, 30.0), Point(20.0, 0.0),
	Point(15.0, 15.0)) ? "Inside\n" : "Outside\n");
	return 0;
}
