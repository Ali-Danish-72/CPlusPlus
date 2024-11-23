/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdanish <mdanish@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 15:43:44 by mdanish           #+#    #+#             */
/*   Updated: 2024/11/23 16:47:22 by mdanish          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/PhoneBook.hpp"

PhoneBook::PhoneBook(void) {
	this->_latestContactAddition = -1;
	return ;
}

PhoneBook::~PhoneBook(void) {
	return ;
}

bool PhoneBook::printContact(int index) {
	if (!this->_contacts[index].getFirstName()[0]) return false;
	std::cout
	<< " \n\tFirst Name: [" << this->_contacts[index].getFirstName()
	<< "]\n\tLast Name: [" << this->_contacts[index].getLastName()
	<< "]\n\tNickname: [" << this->_contacts[index].getNickname()
	<< "]\n\tPhone Number: [" << this->_contacts[index].getPhoneNumber()
	<< "]\n\tDarkest Secret: [" << this->_contacts[index].getDarkestSecret()<< "]\n";
	return true;
}

int PhoneBook::getLatestContactAddition(void) {
	return this->_latestContactAddition;
}

void PhoneBook::addContact(std::string details[5]) {
	if (this->_latestContactAddition == 7) this->_latestContactAddition = -1;
	this->_latestContactAddition++;
	this->_contacts[this->_latestContactAddition].setFirstName(details[0]);
	this->_contacts[this->_latestContactAddition].setLastName(details[1]);
	this->_contacts[this->_latestContactAddition].setNickname(details[2]);
	this->_contacts[this->_latestContactAddition].setPhoneNumber(details[3]);
	this->_contacts[this->_latestContactAddition].setDarkestSecret(details[4]);
}

void PhoneBook::getContactPreview(void) {
	std::cout << "|" << std::setw(10) << "INDEX";
	std::cout << "|" << std::setw(10) << "FIRST NAME";
	std::cout << "|" << std::setw(10) << "LAST NAME";
	std::cout << "|" << std::setw(10) << "NICKNAME" << "|\n";
	for (int index = 0; index < 8; index++) {
		if (!this->_contacts[index].getFirstName()[0])
			continue;
		std::cout << "|" << std::setw(10) << index + 1;
		std::string data = this->_contacts[index].getFirstName();
		if (data.length() > 10) data.resize(9), data += ".";
		std::cout << "|" << std::setw(10) << data;
		data = this->_contacts[index].getLastName();
		if (data.length() > 10) data.resize(9), data += ".";
		std::cout << "|" << std::setw(10) << data;
		data = this->_contacts[index].getNickname();
		if (data.length() > 10) data.resize(9), data += ".";
		std::cout << "|" << std::setw(10) << data << "|\n";
	}
}
