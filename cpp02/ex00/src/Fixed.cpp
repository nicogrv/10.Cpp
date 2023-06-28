#include "../Include/Fixed.hpp"

const int Fixed::_mvBit = 8;

Fixed::Fixed()
{
    this->_nf = 0;
    std::cout << "Default constructor called\n";
}

void Fixed::setRawBits( int const raw)
{
    this->_nf = raw;
    std::cout << "Set\n";
}

int    Fixed::getRawBits(void) const 
{
    std::cout << "getRawBits member function called\n";
    return (this->_nf);
}

Fixed::Fixed(Fixed const &cpy)
{
    std::cout << "Copy constructor called\n";
    this->_nf = cpy.getRawBits();
}

Fixed	&Fixed::operator=(const Fixed &src)
{
    std::cout << "Copy assignment operator called\n";
    this->_nf = src.getRawBits();
    return (*this);
}

Fixed::~Fixed()
{
    std::cout << "Destructor called\n";
}
/*
Default constructor called
Copy constructor called
Copy assignment operator called 
getRawBits member function called
Default constructor called
Copy assignment operator called
getRawBits member function called
getRawBits member function called
0
getRawBits member function called
0
getRawBits member function called
0
Destructor called
Destructor called
Destructor called
*/