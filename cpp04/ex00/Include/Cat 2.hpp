#ifndef CAT_HPP
    #define CAT_HPP
    #include <iostream>
    #include "./Animal.hpp"

class Cat : public Animal
{
    public:
        Cat();
        Cat(Cat const &cpy);
        Cat	&operator=(const Cat &src);
        ~Cat();
};


#endif