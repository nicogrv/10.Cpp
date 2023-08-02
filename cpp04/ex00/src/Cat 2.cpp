#include "../Include/Cat.hpp"

Cat::Cat() : Animal()
{
    std::cout << "Cat life" << std::endl;
    this->sound = "MIAOU MIAOU";
    this->type = "Cat";
}
Cat::Cat(Cat const &cpy) : Animal()
{
    std::cout << "Cat cpy life" << std::endl;
    this->sound = cpy.sound;
    this->type = cpy.type;

}
Cat	&Cat::operator=(const Cat &src)
{
    std::cout << "Cat = op" << std::endl;
    this->sound = src.sound;
    this->type = src.type;
    return (*this);
}
Cat::~Cat()
{
    std::cout << "Cat dead" << std::endl;
}