/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdanish <mdanish@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 11:16:08 by mdanish           #+#    #+#             */
/*   Updated: 2024/11/25 18:00:07 by mdanish          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/util.hpp"

int main(int ac, char **av) {
	if (ac != 4) {
		std::cerr << "Please provide the following arguments:\n"
		<< "<filename> <string1> <string2>\n";
		return 1;
	}
	std::ifstream inputFile(av[1]);
	if (inputFile.rdstate()) {
		inputFile.close();
		std::cerr << "Error in opening the file\n";
		return 2;
	}
	std::stringbuf fileContainer;
	inputFile.get(fileContainer, 0);
	if ((inputFile.rdstate() ^ std::ios_base::eofbit)) {
		inputFile.close();
		std::cerr << "Error in reading the file\n";
		return 3;
	}
	std::string store = findAndReplaceStrings(fileContainer.str(), av[2], av[3]);
	std::ofstream outputFile(av[1] + (std::string)".replace");
	if (outputFile.rdstate()) {
		inputFile.close();
		outputFile.close();
		std::cerr << "Error in opening the replacement file\n";
		return 4;
	}
	outputFile.write(store.c_str(), store.length());
	return 0;
}
