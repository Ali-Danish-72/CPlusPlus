/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdanish <mdanish@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 15:41:56 by mdanish           #+#    #+#             */
/*   Updated: 2024/11/23 16:47:45 by mdanish          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include <iostream>
#include <iomanip>
#include "../includes/Contact.hpp"

class PhoneBook {
	private:
		Contact _contacts[8];
		int     _latestContactAddition;


	public:
		PhoneBook(void);
		~PhoneBook(void);
		bool printContact(int index);
		int  getLatestContactAddition(void);
		void addContact(std::string details[5]);
		void getContactPreview(void);
};

#endif
