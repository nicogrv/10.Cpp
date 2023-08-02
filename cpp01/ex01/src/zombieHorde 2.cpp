#include "../Include/Zombie.hpp"

Zombie* zombieHorde( int N, std::string name )
{
    int i = -1;
    if (N < 0)
        return (NULL);
    Zombie* lescopains = new Zombie[N];
    while (++i < N)
        lescopains[i].give_name(name);
    return (lescopains);
}