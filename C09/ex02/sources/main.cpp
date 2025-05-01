/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdanish <mdanish@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 17:14:32 by mdanish           #+#    #+#             */
/*   Updated: 2025/02/27 19:06:26 by mdanish          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/PmergeMe.hpp"

int main(int ac, char **av) {
	if (ac < 2) {
		std::cerr << "Usage as follows:\n./PmergeMe [numbers to sort]\n";
		return 1;
	}

	PmergeMe sorter;
	try {
		sorter.verification(av);
		sorter.printTheNumbers("Before: ");
		sorter.sortTheVector();
		sorter.sortTheDeque();
		sorter.printTheNumbers("After: ");
		std::cout << "Time to process a range of " << sorter.getSize() << " elements with std::deque : ";
		std::cout << std::fixed << std::setprecision(5) << sorter.getTimeForDeque() << " us\n";
		std::cout << "Time to process a range of " << sorter.getSize() << " elements with std::vector : ";
		std::cout << std::fixed << std::setprecision(5) << sorter.getTimeForVector() << " us\n";
	} catch (std::runtime_error & error) {
		std::cerr << error.what() << '\n';
		return 2;
	}
	return 0;
}
