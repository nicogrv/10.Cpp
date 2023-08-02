#include "../Include/Dog.hpp"

Dog::Dog() : Animal()
{
    std::cout << "Dog life" << std::endl;
    this->sound = "WOUAF WOUAF CEST PIERRE LE CABO";
    this->type = "Dog";
}
Dog::Dog(Dog const &cpy) : Animal()
{
    std::cout << "Dog cpy life" << std::endl;
    this->sound = cpy.sound;
    this->type = cpy.type;

}
Dog	&Dog::operator=(const Dog &src)
{
    std::cout << "Dog = op" << std::endl;
    this->sound = src.sound;
    this->type = src.type;
    return (*this);
}
Dog::~Dog()
{
    std::cout << "Dog dead" << std::endl;
}