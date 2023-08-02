#ifndef FIXED_HPP
    #define FIXED_HPP
    #include <iostream>

class Fixed
{

    public:
        Fixed();
        Fixed(Fixed const &cpy);
        ~Fixed();

        int getRawBits( void ) const;
        void setRawBits( int const raw );

        Fixed	&operator=(const Fixed &src);

    private:

        int _nf;
        static const int _mvBit; 
};

#endif
