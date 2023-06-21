#include "../Include/Zombie.hpp"

void    Zombie::announce()
{
    std::cout << this->name << ":  BraiiiiiiinnnzzzZ...";
    return ;
}

Zombie::Zombie( std::string name){
    this->name = name;
    return ;
}