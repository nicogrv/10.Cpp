#include "../Include/Dog.hpp"
#include "../Include/Animal.hpp"
#include "../Include/WrongAnimal.hpp"
#include "../Include/Cat.hpp"
#include "../Include/WrongCat.hpp"


int main()
{
	Dog basic;
	basic.setIdeas("Bonjour;;;;;;;;;;;;;;;;;");
	{
		Dog tmp = basic;
		basic.setIdeas("salut....................");
		std::cout << basic.getIdeas() << std::endl;
		std::cout << tmp.getIdeas() << std::endl;
	}

	
	return 0;
}