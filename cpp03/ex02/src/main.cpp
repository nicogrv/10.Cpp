#include "../Include/ClapTrap.hpp"
#include "../Include/ScavTrap.hpp"
#include "../Include/FragTrap.hpp"


int main( void ) 
{
    // ScavTrap b("Titou");
    FragTrap c("Pierre");
    c.attack("Titou");
    c.highFivesGuys();
    return 0;
}