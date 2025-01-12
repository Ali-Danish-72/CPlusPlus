/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdanish <mdanish@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 08:36:35 by mdanish           #+#    #+#             */
/*   Updated: 2025/01/12 08:38:03 by mdanish          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Serializer.hpp"

uintptr_t Serializer::serialize(Data * data) {
	return reinterpret_cast<uintptr_t>(data);
}

Data * Serializer::deserialize(uintptr_t raw) {
	return reinterpret_cast<Data *>(raw);
}
