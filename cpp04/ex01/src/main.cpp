#include "../Include/Dog.hpp"
#include "../Include/Animal.hpp"
#include "../Include/Cat.hpp"


int main()
{
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	std::cout << "\n\n";
	delete j;//should not create a leak
	delete i;
	return 0;
}