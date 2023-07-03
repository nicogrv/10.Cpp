#ifndef FRAGTRAP_HPP
    #define FRAGTRAP_HPP
    #include "./ClapTrap.hpp"

class FragTrap : public ClapTrap
{
    public:
        FragTrap(std::string name);
        FragTrap(FragTrap const &cpy);
        FragTrap	&operator=(const FragTrap &src);
        ~FragTrap();

        void highFivesGuys(void);


    private:
        /* data */

};


#endif

