#include "../Include/Dog.hpp"
#include "../Include/Animal.hpp"
#include "../Include/WrongAnimal.hpp"
#include "../Include/Cat.hpp"
#include "../Include/WrongCat.hpp"


int main()
{
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	std::cout << "------\n";

	delete j;
	delete i;
	std::cout << "------\n";


	int tab = 6;
	Animal *A[tab];
	for (int index = 0; index < tab / 2; index++)
		A[index] = new Cat();
	std::cout << "------\n";
	for (int index = tab / 2; index < tab; index++)
		A[index] = new Dog();
	std::cout << "------\n";
	for (int index = 0; index < tab; index++)
		delete (Animal *) A[index];



	std::cout << "------\n";

	Cat cat = Cat();
	std::cout << "------\n";
	Cat catcpy = Cat();
	std::cout << "------\n";

	cat.setIdeas("bonjour");
	std::cout << "------\n";
	std::cout << cat.getIdeas() << std::endl;


	catcpy = cat;

	std::cout << "------\n";
	std::cout << catcpy.getIdeas() << std::endl;

	catcpy.setIdeas("salut");


	std::cout << "------\n";
	std::cout << cat.getIdeas() << std::endl;

	std::cout << "------\n";
	std::cout << catcpy.getIdeas() << std::endl;
	std::cout << "------\n";


	Dog basic;
	{
		Dog tmp = basic;
	}

	
	return 0;
}