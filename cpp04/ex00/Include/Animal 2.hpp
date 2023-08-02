#ifndef ANIMAL_HPP
    #define ANIMAL_HPP
    #include <iostream>

class Animal
{
    public:
        Animal();
        Animal(Animal const &cpy);
        Animal	&operator=(const Animal &src);
        ~Animal();

        std::string getType() const;
        void makeSound() const;

    protected:
        std::string type;
        std::string sound;

};

#endif