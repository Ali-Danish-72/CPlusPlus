/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdanish <mdanish@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 14:31:22 by mdanish           #+#    #+#             */
/*   Updated: 2025/01/23 16:31:31 by mdanish          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <algorithm>

template <class T> typename T::const_iterator easyfind(const T & container, const int toFind) {
	return std::find(container.begin(), container.end(), toFind);
}

template <class T> typename T::iterator easyfind(T & container, const int toFind) {
	return std::find(container.begin(), container.end(), toFind);
}
