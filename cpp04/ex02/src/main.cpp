#include "../Include/Dog.hpp"
#include "../Include/Animal.hpp"
#include "../Include/WrongAnimal.hpp"
#include "../Include/Cat.hpp"
#include "../Include/WrongCat.hpp"


int main()
{
	// Animal test; 
	Animal *cat = new Cat();

	cat->makeSound();
}