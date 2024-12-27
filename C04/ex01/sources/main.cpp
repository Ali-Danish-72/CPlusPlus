/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdanish <mdanish@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/22 23:14:18 by mdanish           #+#    #+#             */
/*   Updated: 2024/12/27 15:48:40 by mdanish          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "../includes/WrongCat.hpp"
#include "../includes/Cat.hpp"
#include "../includes/Dog.hpp"
#include <iostream>

int main() {
	// const Animal* meta1 = new Animal();
// 	const Animal* j = new Dog();
// 	const Animal* i = new Cat();
// 	const WrongAnimal* meta2 = new WrongAnimal();
// 	const WrongAnimal* k = new WrongCat();

	Animal *animals[10];

	for (int i = 0; i < 5; i++) {
		animals[i] = new Dog();
		animals[i + 5] = new Cat();
	}

	// std::cout << j->getType() << " " << std::endl;
	// std::cout << i->getType() << " " << std::endl;
	// std::cout << k->getType() << " " << std::endl;
	// i->makeSound(); //will output the cat sound!
	// j->makeSound();
	// k->makeSound(); //will output the wrong cat sound!
	// meta1->makeSound();
	// meta2->makeSound();
	static_cast<Dog *>(animals[0])->addIdea("I am a Dog");
	static_cast<Dog *>(animals[0])->addIdea("I am not a Cat");
	static_cast<Dog *>(animals[0])->addIdea("Cats are much better");
	static_cast<Dog *>(animals[0])->addIdea("Long live Cats!");

	Animal * dog = new Animal(*animals[0]);

	std::cout << "original |" << static_cast<Dog *>(animals[0])->retrieveIdea(4) << "|\n";
	std::cout << "original |" << static_cast<Dog *>(animals[0])->retrieveIdea(5) << "|\n";
	std::cout << "copy |" << static_cast<Dog *>(dog)->retrieveIdea(4) << "|\n";
	std::cout << "copy |" << static_cast<Dog *>(dog)->retrieveIdea(5) << "|\n";

	std::cout << "\n* added an idea to the original *\n\n";
	static_cast<Dog *>(animals[0])->addIdea("I like Cats as a Dog.");

	std::cout << "original |" << static_cast<Dog *>(animals[0])->retrieveIdea(4) << "|\n";
	std::cout << "original |" << static_cast<Dog *>(animals[0])->retrieveIdea(5) << "|\n";
	std::cout << "copy |" << static_cast<Dog *>(dog)->retrieveIdea(4) << "|\n";
	std::cout << "copy |" << static_cast<Dog *>(dog)->retrieveIdea(5) << "|\n";

	// delete meta1;
	// delete meta2;
	// delete i;
	// delete j;
	// delete k;

	for (int i = 0; i < 10; i++)
		delete animals[i];

	return 0;
}