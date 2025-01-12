/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Converter.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdanish <mdanish@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 03:16:49 by mdanish           #+#    #+#             */
/*   Updated: 2025/01/12 04:49:21 by mdanish          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>
#include <iostream>
#include <limits>
#include <cctype>
#include <cmath>
#include <cstdlib>

class ScalarConverter {
	private:
		ScalarConverter();
		ScalarConverter(const ScalarConverter & other);
		~ScalarConverter();
		ScalarConverter & operator = (const ScalarConverter & other);

	public:
		static void convert(std::string value);
};
