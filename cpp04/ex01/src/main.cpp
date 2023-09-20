#include "../Include/Dog.hpp"
#include "../Include/Animal.hpp"
#include "../Include/Cat.hpp"


int main()
{
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	delete j;
	delete i;
	{
		Cat* cat = new Cat();
		cat->setBrain("Salut", 0);
		cat->setBrain("Ca va", 1);
		std::cout << cat->getBrain(0) << std::endl;
		std::cout << cat->getBrain(1) << std::endl;
		std::cout << cat->getBrain(50) << std::endl;
		delete cat;
	}
	std::cout << "------------------------------------------------------" << std::endl;
	{
		Cat cat;
		Cat catClone;
		cat.setBrain("test cpy", 60);
		catClone = cat;
		std::cout << "CPY CAT:\t\t" << catClone.getBrain(60) << std::endl;

	}
	std::cout << "------------------------------------------------------" << std::endl;
	{
		Cat cat;
		cat.setBrain("test cpy", 60);
		Cat catClone(cat);
		std::cout << "CPY CAT:\t\t" << catClone.getBrain(60) << std::endl;
	}
	std::cout << "------------------------------------------------------" << std::endl;
	{
		Cat test;
		Cat test2 = test;
	}
	std::cout << "------------------------------------------------------" << std::endl;
	std::cout << "------------------------------------------------------" << std::endl;
	{
		Dog* dog = new Dog();
		dog->setBrain("Salut", 0);
		dog->setBrain("Ca va", 103);
		std::cout << dog->getBrain(0) << std::endl;
		std::cout << dog->getBrain(1) << std::endl;
		std::cout << dog->getBrain(50) << std::endl;
		delete dog;
	}
	{
		Dog dog;
		Dog dogClone;
		dog.setBrain("test cpy", 60);
		dogClone = dog;
		std::cout << "CPY dog:\t\t" << dogClone.getBrain(60) << std::endl;

	}
	std::cout << "------------------------------------------------------" << std::endl;

	{
		Dog dog;
		dog.setBrain("test cpy", 60);
		Dog dogClone(dog);
		std::cout << "CPY dog:\t\t" << dogClone.getBrain(60) << std::endl;
	}
	std::cout << "------------------------------------------------------" << std::endl;

	{
		Dog test;
		Dog test2 = test;
	}
	std::cout << "------------------------------------------------------" << std::endl;
	{
		Dog dog;
		dog.setBrain("test cpy", -10);
		dog.setBrain("test cpy", 10);
		dog.setBrain("test cpy", 100);
	}

	Animal* z[20];
	for (int i = 0; i < 20; i++)
	{
		if (i < 10)
			z[i] = new Cat();
		else
			z[i] = new Dog(); 
	}
	for (int i = 0; i < 20; i++)
		delete(Animal *) z[i];
}