#ifndef CLAPTRAP_HPP
    #define CLAPTRAP_HPP
    #include <iostream>
    #include <stdlib.h>

class ClapTrap
{

    public:
        ClapTrap(std::string name);
        ClapTrap(ClapTrap const &cpy);
        ClapTrap	&operator=(const ClapTrap &src);
        ~ClapTrap();

        void attack(const std::string& target); 
        void takeDamage(unsigned int amount);
        void beRepaired(unsigned int amount);

    protected:
        std::string _name;
        unsigned int _hitPoints;
        unsigned int _energiePoints;
        unsigned int _attackDamage;

};

#endif
