/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdanish <mdanish@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 08:29:00 by mdanish           #+#    #+#             */
/*   Updated: 2025/01/12 08:39:05 by mdanish          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <cstdint>

struct Data {
	int index;
	char tag;
};

class Serializer {
	private:
		Serializer();
		Serializer(const Serializer & other);
		~Serializer();
		Serializer & operator = (const Serializer & other);

	public:
		static uintptr_t serialize(Data * data);
		static Data * deserialize(uintptr_t raw);
};
