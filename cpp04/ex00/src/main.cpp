#include "../Include/Dog.hpp"
#include "../Include/Animal.hpp"
#include "../Include/Cat.hpp"
#include "../Include/WrongCat.hpp"
#include "../Include/WrongAnimal.hpp"


int main()
	{
	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	const WrongAnimal* Wrong = new WrongCat();
	std::cout << "--------------------------------" << std::endl;
	std::cout << meta->getType() << " " << std::endl;
	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	std::cout << Wrong->getType() << " " << std::endl;
	std::cout << "--------------------------------" << std::endl;
	meta->makeSound();
	j->makeSound();
	i->makeSound(); //will output the cat sound!
	Wrong->makeSound();
	std::cout << "--------------------------------" << std::endl;

	delete meta;
	delete i;
	delete j;
	delete Wrong;
	
	return 0;
}