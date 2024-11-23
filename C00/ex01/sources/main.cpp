/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdanish <mdanish@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 17:44:18 by mdanish           #+#    #+#             */
/*   Updated: 2024/11/23 16:28:32 by mdanish          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/PhoneBook.hpp"
#include <string>
#include <cctype>
#include <cstdlib>

void	addNewContact(PhoneBook *phonebook) {
	std::string details[5];

	while (!details[0][0]) {
		std::cout << "\nPlease enter the First Name: ";
		if (!std::getline(std::cin, details[0])) return (void)(std::cout << "\n");
		if (!details[0][0]) std::cout << "First Name can not be empty.\n";
	}
	while (!details[1][0]) {
		std::cout << "Please enter the Last Name: ";
		if (!std::getline(std::cin, details[1])) return (void)(std::cout << "\n");
		if (!details[1][0]) std::cout << "Last Name can not be empty.\n";
	}
	while (!details[2][0]) {
		std::cout << "Please enter the Nickname: ";
		if (!std::getline(std::cin, details[2])) return (void)(std::cout << "\n");
		if (!details[2][0]) std::cout << "Nickname can not be empty.\n";
	}
	while (!details[3][0]) {
		std::cout << "Please enter the Phone Number: ";
		if (!std::getline(std::cin, details[3])) return (void)(std::cout << "\n");
		if (!details[3][0]) std::cout << "Phone Number can not be empty.\n";
		for (int index = 0; index < (int)details[3].length(); index++)
			if (!std::isdigit(details[3][index])) {
				std::cout << "The Phone Number must only contain numbers\n";
				details[3].clear();
				break;
			}
	}
	while (!details[4][0]) {
		std::cout << "Please enter the Darkest Secret: ";
		if (!std::getline(std::cin, details[4])) return (void)(std::cout << "\n");
		if (!details[4][0]) std::cout << "Darkest Secret can not be empty.\n";
	}
	phonebook->addContact(details);
	std::cout << "\nEnter a command: ";
}

void	displaySearchMenu(PhoneBook phonebook) {
	std::string input;
	int index;

	phonebook.getContactPreview();
	bool validIndex = phonebook.getLatestContactAddition() == -1 ? true : false;
	while (!validIndex) {
		std::cout << "\nEnter the index of the contact to display: ";
		if (!std::getline(std::cin, input)) return ;
		try {
			if (!input[0])
				throw "Please enter an index.\n";
			for (int i = 0; i < (int)input.length(); i++)
				if (!std::isdigit(input[i]))
					throw "The index can only be numeric.\n";
		} catch (const char *err) {
			std::cout << err;
			continue;
		}
		index = std::atoi(input.c_str());
		index > 0 && index < 9 && phonebook.printContact(index - 1) ?
		validIndex = true : (bool)(std::cout << "The index entered is invalid.\n");
	}
	std::cout << "\nEnter a command: ";
}

int main() {
	PhoneBook phonebook;
	std::string command;

	std::cout << "Enter a command: ";
	while (std::getline(std::cin, command)) {
		if (command == "EXIT") return 0;
		if (command == "ADD") addNewContact(&phonebook);
		else if (command == "SEARCH") displaySearchMenu(phonebook);
		else std::cout << "The command {" << command
		<< "} is invalid. Please use one of the following:\n"
		<< "[ADD] / [SEARCH] / [EXIT]\nEnter a command: ";
	}
	std::cout << "\n";
	return 0;
}
