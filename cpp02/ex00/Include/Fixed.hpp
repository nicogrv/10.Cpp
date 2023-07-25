#ifndef FIXED_HPP
    #define FIXED_HPP
    #include <iostream>

class Fixed
{

    public:
        Fixed();
        Fixed(Fixed const &cpy);
        ~Fixed();
        Fixed	&operator=(const Fixed &src);

        int getRawBits( void ) const;
        void setRawBits( int const raw );


    private:

        int _nf;
        static const int _mvBit; 
};

#endif
