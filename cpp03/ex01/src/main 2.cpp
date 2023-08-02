#include "../Include/ClapTrap.hpp"
#include "../Include/ScavTrap.hpp"


int main( void ) 
{
    ClapTrap a("Nico");
    ScavTrap b("Titou");

    b.attack("bob");
    a.attack("Pierre");
    b.takeDamage(99);
    a.takeDamage(11);
    b.beRepaired(10);
    a.attack("Pierre");
    b.attack("Pierre");

    return 0;
}