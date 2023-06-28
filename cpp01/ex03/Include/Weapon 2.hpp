#ifndef WEAPON_HPP
    #define WEAPON_HPP
    #include <iostream>

    class Weapon{
        public:
            std::string& getType();
            void setType( std::string name_type );
            Weapon( std::string name );
            Weapon( void );

            ~Weapon();

        private:
            std::string type;
    };

#endif