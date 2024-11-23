#include <iostream>
#include <cctype>
#include <string>

std::string megaphone(std::string message) {
	std::size_t length = message.length();
	for (std::size_t i = 0; i < length; i++)
		message[i] = std::toupper(message[i]);
	return message;
}

int main(int ac, char **av) {
	if (ac == 1) return std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *\n", 0;
	for (int i = 1; i < ac; i++) 
		std::cout << megaphone(av[i]);
	std::cout << "\n";
}
