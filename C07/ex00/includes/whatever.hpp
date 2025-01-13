/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdanish <mdanish@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 20:53:23 by mdanish           #+#    #+#             */
/*   Updated: 2025/01/13 21:11:49 by mdanish          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

template <typename T> void swap(T & a, T & b) {
	T store = a;
	a = b;
	b = store;
}

template <typename T> T min(T & a, T & b) {
	return a < b ? a : b;
}

template <typename T> T max(T & a, T & b) {
	return a > b ? a : b;
}
