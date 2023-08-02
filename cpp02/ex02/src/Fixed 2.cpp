#include "../Include/Fixed.hpp"

const int Fixed::_mvBit = 8;


void Fixed::setRawBits( int const raw)
{
    this->_nf = raw;
}

int    Fixed::getRawBits(void) const 
{
    return (this->_nf);
}


Fixed Fixed::min(Fixed &fixed1, Fixed &fixed2)
{
    if (fixed1 < fixed2)
        return (fixed1);
    return (fixed2);
}

Fixed Fixed::min(const Fixed &fixed1, const Fixed &fixed2)
{
    if (fixed1 < fixed2)
        return (fixed1);
    return (fixed2);
}

Fixed Fixed::max(Fixed &fixed1, Fixed &fixed2)
{
    if (fixed1 < fixed2)
        return (fixed2);
    return (fixed1);
}

Fixed Fixed::max(const Fixed &fixed1, const Fixed &fixed2)
{
    if (fixed1 < fixed2)
        return (fixed2);
    return (fixed1);
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
}
Fixed::Fixed(int nbr)
{
    this->_nf =  nbr << this->_mvBit;

}
Fixed::Fixed(float nbr)
{
    
    this->_nf =  roundf(nbr * (1 << this->_mvBit));
}

Fixed::Fixed(Fixed const &cpy)
{
    this->_nf = cpy._nf;
}

Fixed	&Fixed::operator=(const Fixed &src)
{
    this->_nf = src._nf;
    return (*this);
}

bool	Fixed::operator>(const Fixed &src) const
{
    if (this->_nf > src._nf)
        return (true);
    return (false);
}

bool	Fixed::operator<(const Fixed &src) const
{
    if (this->_nf < src._nf)
        return (true);
    return (false);
}

bool	Fixed::operator>=(const Fixed &src) const
{
    if (this->_nf >= src._nf)
        return (true);
    return (false);
}

bool	Fixed::operator<=(const Fixed &src) const
{
    if (this->_nf <= src._nf)
        return (true);
    return (false);
}

bool	Fixed::operator==(const Fixed &src) const
{
    if (this->_nf == src._nf)
        return (true);
    return (false);
}

bool	Fixed::operator!=(const Fixed &src) const
{
    if (this->_nf != src._nf)
        return (true);
    return (false);
}

float	Fixed::operator+(const Fixed &src)
{
    return (this->toFloat() + src.toFloat());
}

float	Fixed::operator-(const Fixed &src)
{
    return (this->toFloat() - src.toFloat());
}

float	Fixed::operator*(const Fixed &src)
{
    return (this->toFloat() * src.toFloat());
}

float	Fixed::operator/(const Fixed &src)
{
    return (this->toFloat() / src.toFloat());
}

Fixed	&Fixed::operator++()
{
    this->_nf = this->_nf + 1;
	return (*this);
}

Fixed	Fixed::operator++( int )
{
	Fixed	operation(*this);

	this->_nf = this->_nf + 1;
	return (operation);
}

Fixed	&Fixed::operator--()
{
	this->_nf = this->_nf - 1;
	return (*this);
}

Fixed	Fixed::operator--(int)
{
	Fixed	operation(*this);

	this->_nf = this->_nf - 1;
	return (operation);
}




std::ostream&	operator<< ( std::ostream &os, const Fixed &cls )
{
    os << cls.toFloat();
    return (os);
}
Fixed::~Fixed()
{
    return ;
}