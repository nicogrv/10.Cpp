#include "../Include/Zombie.hpp"

int main()
{
    Zombie *Boo = newZombie("Boo");
    Boo->announce();
    randomChump("Zoo");
    delete Boo;
    return (0);
}