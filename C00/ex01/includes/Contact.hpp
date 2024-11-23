/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdanish <mdanish@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 16:39:51 by mdanish           #+#    #+#             */
/*   Updated: 2024/11/23 16:47:12 by mdanish          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP

#include <string>

class Contact {
	private:
		std::string _firstName;
		std::string _lastName;
		std::string _nickname;
		std::string _number;
		std::string _darkestSecret;

	public:
		Contact(void);
		~Contact(void);
		void setFirstName(std::string name);
		void setLastName(std::string name);
		void setNickname(std::string name);
		void setPhoneNumber(std::string number);
		void setDarkestSecret(std::string secret);
		std::string getFirstName(void);
		std::string getLastName(void);
		std::string getNickname(void);
		std::string getPhoneNumber(void);
		std::string getDarkestSecret(void);
};

#endif
