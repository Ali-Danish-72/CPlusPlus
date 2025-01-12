/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdanish <mdanish@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 08:38:30 by mdanish           #+#    #+#             */
/*   Updated: 2025/01/12 09:40:33 by mdanish          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Classes.hpp"

int main() {
	Base * store;
	store = generate();
	identify(store);
	identify(*store);
	delete store;
	store = generate();
	identify(store);
	identify(*store);
	delete store;
	store = generate();
	identify(store);
	identify(*store);
	delete store;
	store = generate();
	identify(store);
	identify(*store);
	delete store;
	store = generate();
	identify(store);
	identify(*store);
	delete store;
	// Base a;
	// identify(a);
	return 0;
}
