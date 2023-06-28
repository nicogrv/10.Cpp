#include "../Include/Zombie.hpp"

void    Zombie::announce()
{
    std::cout << this->name << ":  BraiiiiiiinnnzzzZ..." << std::endl;
    return ;
}

Zombie::Zombie( std::string name){
    std::cout << name << " life" << std::endl;
    this->name = name;
    return ;
}

Zombie::~Zombie(){
    std::cout << this->name << " dead" << std::endl;
}