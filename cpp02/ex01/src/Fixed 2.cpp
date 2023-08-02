#include "../Include/Fixed.hpp"

const int Fixed::_mvBit = 8;


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

int Fixed::toInt() const
{
    return (this->_nf >> this->_mvBit);
}

float Fixed::toFloat() const
{
    return ((float)this->_nf / (1 << this->_mvBit));
}


Fixed::Fixed()
{
    this->_nf = 0;
    std::cout << "Default constructor called\n";
}
Fixed::Fixed(int nbr)
{
    std::cout << "Int constructor called\n";
    this->_nf =  nbr << this->_mvBit;

}
Fixed::Fixed(float nbr)
{
    
    std::cout << "Float constructor called\n";
    this->_nf =  roundf(nbr * (1 << this->_mvBit));
}

Fixed::Fixed(Fixed const &cpy)
{
    std::cout << "Copy constructor called\n";
    this->_nf = cpy._nf;
}

Fixed	&Fixed::operator=(const Fixed src)
{
    std::cout << "Copy assignment operator called\n";
    this->_nf = src._nf;
    return (*this);
}


std::ostream&	operator<< ( std::ostream &os, const Fixed &cls )
{
    os << cls.toFloat();
    return (os);
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