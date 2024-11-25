/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdanish <mdanish@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 17:59:05 by mdanish           #+#    #+#             */
/*   Updated: 2024/11/25 17:59:40 by mdanish          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/util.hpp"

std::string findAndReplaceStrings(std::string fileData, std::string const &find, std::string const &replace) {
	std::string::size_type pos = 0;
	std::string::size_type oldPos = 0;
	std::string replacedString = "";

	while (pos = fileData.find(find, pos), pos != std::basic_string<char>::npos) {
		replacedString += fileData.substr(oldPos, pos - oldPos) + replace;
		pos += find.length();
		oldPos = pos;
	}
	return oldPos ? replacedString + fileData.substr(oldPos) : fileData;
}
