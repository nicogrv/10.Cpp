#include "../Include/Zombie.hpp"



Zombie::Zombie(){
    std::cout << " life" << std::endl;
    return ;
}

Zombie::~Zombie(){
    std::cout << this->name << " dead" << std::endl;
}

void    Zombie::give_name( std::string name)
{
    this->name = name;
    return ;
}
