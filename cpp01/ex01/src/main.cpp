#include "../Include/Zombie.hpp"

int main()
{
    Zombie* Horde = zombieHorde(20, "Bob");
    delete [] Horde;
    return (0);
}