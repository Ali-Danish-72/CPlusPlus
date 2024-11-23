/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdanish <mdanish@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 16:41:25 by mdanish           #+#    #+#             */
/*   Updated: 2024/11/23 16:47:12 by mdanish          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Contact.hpp"

Contact::Contact(void) {
	return ;
}

Contact::~Contact(void) {
	return ;
}

void Contact::setFirstName(std::string name) {
	this->_firstName = name;
}

void Contact::setLastName(std::string name) {
	this->_lastName = name;
}

void Contact::setNickname(std::string name) {
	this->_nickname = name;
}

void Contact::setPhoneNumber(std::string number) {
	this->_number = number;
}

void Contact::setDarkestSecret(std::string secret) {
	this->_darkestSecret = secret;
}

std::string Contact::getFirstName(void) {
	return this->_firstName;
}

std::string Contact::getLastName(void) {
	return this->_lastName;
}

std::string Contact::getNickname(void) {
	return this->_nickname;
}

std::string Contact::getPhoneNumber(void) {
	return this->_number;
}

std::string Contact::getDarkestSecret(void) {
	return this->_darkestSecret;
}
