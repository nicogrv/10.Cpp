#ifndef FIXED_HPP
    #define FIXED_HPP
    #include <iostream>
    #include <cmath>

class Fixed
{

    public:
        Fixed();
        Fixed(Fixed const &cpy);
        Fixed(int nbr);
        Fixed(float nbr);
        ~Fixed();

        float toFloat( void ) const;
        int toInt( void ) const;
        int getRawBits( void ) const;
        void setRawBits( int const raw );

        Fixed	&operator=(const Fixed src);

    private:

        int _nf;
        static const int _mvBit; 
};

std::ostream&	operator<< ( std::ostream &os, const Fixed &cls );

#endif
