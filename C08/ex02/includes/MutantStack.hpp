/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdanish <mdanish@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 14:44:09 by mdanish           #+#    #+#             */
/*   Updated: 2025/01/28 19:13:47 by mdanish          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <cstdlib>
#include <stack>

template <typename T> class MutantStack : public std::stack<T>{
	public:
		MutantStack<T>(void) :std::stack<T>() {}
		MutantStack<T>(const MutantStack<T> & other) : std::stack<T>(other) {}
		~MutantStack<T>(void) {};
		MutantStack<T> & operator=(const MutantStack<T> & other) {
			if (this != &other)
				this->c = other.c;
			return *this;
		}

		// Iterator Type Definitions
		typedef typename std::stack<T>::container_type::iterator iterator;
		typedef typename std::stack<T>::container_type::const_iterator const_iterator;
		typedef typename std::stack<T>::container_type::reverse_iterator reverse_iterator;
		typedef typename std::stack<T>::container_type::const_reverse_iterator const_reverse_iterator;

		// Iterator Functions
		iterator begin(void) { return this->c.begin();}
		const_iterator begin(void) const { return this->c.begin();}
		reverse_iterator rbegin(void) { return this->c.rbegin();}
		const_reverse_iterator rbegin(void) const { return this->c.rbegin();}

		iterator end(void) { return this->c.end();}
		const_iterator end(void) const { return this->c.end();}
		reverse_iterator rend(void) { return this->c.rend();}
		const_reverse_iterator rend(void) const { return this->c.rend();}

};
