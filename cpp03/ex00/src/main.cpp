#include "../Include/ClapTrap.hpp"


int main( void ) 
{
    ClapTrap a("Nico");
    a.takeDamage(9);
    a.attack("Pierre");
    a.attack("Pierre");
    a.attack("Pierre");
    a.attack("Pierre");
    a.attack("Pierre");
    a.attack("Pierre");
    a.attack("Pierre");
    a.attack("Pierre");
    // a.beRepaired(72);
    // a.takeDamage(1);
    a.attack("Pierre");

    a.attack("Pierre");

    return 0;
}