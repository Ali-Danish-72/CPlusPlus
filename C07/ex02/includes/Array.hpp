/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdanish <mdanish@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 21:36:37 by mdanish           #+#    #+#             */
/*   Updated: 2025/01/14 10:38:13 by mdanish          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <exception>

template <typename T> class Array {
	private:
		T * _array;
		unsigned int _size;

	public:
		Array<T>() : _array(0), _size(0) {}
		Array<T>(unsigned int n) : _array(new T[n]), _size(n) {if (!this->_array) throw MallocFail();}
		Array<T>(const Array<T> & other) : _size(other.size()){
			this->_array = new T[this->_size];
			if (!this->_array) throw MallocFail();
			for (unsigned int i = 0; i < this->_size; ++i)
				this->_array[i] = other._array[i];
		}
		~Array<T>() {delete[] this->_array;}
		Array<T> & operator = (const Array<T> & other) {
			if (this != &other) {
				delete[] this->_array;
				this->_size = other.size();
				this->_array = new T[this->_size];
				if (!this->_array) throw MallocFail();
				for (unsigned int i = 0; i < this->_size; ++i)
					this->_array[i] = other._array[i];
			}
			return *this;
		}

		class OutOfBoundsAccess : public std::exception {
			const char * what() const throw() {
				return "The index points to a memory that is out of bounds.";
			}
		};

		class NullPointerAccess : public std::exception {
			const char * what() const throw() {
				return "An attempt to access a NULL pointer has been made.";
			}
		};

		class MallocFail : public std::exception {
			const char * what() const throw() {
				return "A malloc call has failed.";
			}
		};

		T & operator [] (unsigned int index) {
			if (!this->_array) throw NullPointerAccess();
			if (index >= this->_size) throw OutOfBoundsAccess();
			return this->_array[index];
		}

		const T & operator [] (unsigned int index) const {
			if (!this->_array) throw NullPointerAccess();
			if (index >= this->_size) throw OutOfBoundsAccess();
			return this->_array[index];
		}

		unsigned int size(void) const {
			return this->_size;
		}
};
