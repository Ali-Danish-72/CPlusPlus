/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdanish <mdanish@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 21:15:25 by mdanish           #+#    #+#             */
/*   Updated: 2025/01/13 21:27:56 by mdanish          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>

template <typename T > void iter(T *array, int length, void (*func)(T index)) {
	for (int i = 0; i < length; ++i)
		func(array[i]);
}

template <typename T> void testprint(T toPrint) {
	std::cout << toPrint << '\n';
}
