#include "../Include/iter.hpp"
#include <iostream>

int testInt(int e) {
	return (e *100);
}

int testInt2(int e) {
	return (e + (e/100));
}

std::string testString(std::string e) {
	
	return (e + " ca va ?");
}

int main( void ) { 
	{
		int nb[9] = {1, 2, 3, 4, 5, 6, 7, 8 ,9};

		iter(nb, 9, testInt);
		for (int j = 0; j < 9; j++) {
			std::cout << nb[j] << std::endl;
		}
		std::cout << std::endl;
		iter(nb, 9, testInt2);
		for (int j = 0; j < 9; j++) {
			std::cout << nb[j] << std::endl;
		}
	}
	std::cout << std::endl;
	{
		std::string str[3] = {"Bonjour","Salut","Hello"};

		iter(str, 3, testString);
		for (int j = 0; j < 3; j++) {
			std::cout << str[j] << std::endl;
		}
	}
}
