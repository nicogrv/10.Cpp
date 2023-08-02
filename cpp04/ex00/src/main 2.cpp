#include "../Include/Animal.hpp"
#include "../Include/Cat.hpp"
#include "../Include/Dog.hpp"


int main() {
    const Animal* meta = new Animal();
    const Animal* j = new Dog();
    const Animal* i = new Cat();
    const Cat* e = new Cat();

    std::cout << j->getType() << " " << std::endl;
    std::cout << i->getType() << " " << std::endl;
    i->makeSound(); //will output the cat sound! 
    j->makeSound();
    meta->makeSound();

    delete meta;
    delete j;
    delete i;
    delete e;
return 0; }