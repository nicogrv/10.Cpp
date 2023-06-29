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

        static Fixed min(Fixed &fixed1, Fixed &fixed2);
        static Fixed min(const Fixed &fixed1, const Fixed &fixed2);

        static Fixed max(Fixed &fixed1, Fixed &fixed2);
        static Fixed max(const Fixed &fixed1, const Fixed &fixed2);

        Fixed	&operator=(const Fixed &src);

        bool	operator>(const Fixed &src) const;
        bool	operator<(const Fixed &src) const;
        bool	operator>=(const Fixed &src) const;
        bool	operator<=(const Fixed &src) const;
        bool	operator==(const Fixed &src) const;
        bool	operator!=(const Fixed &src) const;

        float	operator+(const Fixed &src);
        float	operator-(const Fixed &src);
        float	operator*(const Fixed &src);
        float	operator/(const Fixed &src);

        Fixed	&operator++();
        Fixed	operator++(int);
        Fixed	&operator--();
        Fixed	operator--(int);



    private:

        int _nf;
        static const int _mvBit; 
};

std::ostream&	operator<< ( std::ostream &os, const Fixed &cls );

#endif
