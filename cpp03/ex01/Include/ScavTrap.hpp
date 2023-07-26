#ifndef SCAVTRAP_HPP
    #define SCAVTRAP_HPP
    #include "./ClapTrap.hpp"

class ScavTrap : public ClapTrap
{
    public:
        ScavTrap(std::string name);
        ScavTrap(ScavTrap const &cpy);
        ScavTrap	&operator=(const ScavTrap &src);
        ~ScavTrap();

        void guardGate();
        void attack(const std::string& target); 

};


#endif

