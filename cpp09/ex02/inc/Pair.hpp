/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Pair.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngriveau <ngriveau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 14:47:48 by ngriveau          #+#    #+#             */
/*   Updated: 2024/02/20 17:37:31 by ngriveau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PAIR_HPP
	#define PAIR_HPP
	#include <vector>
	#include <iostream>

	#define NC "\033[0m"
	#define RED "\033[0;31m"
	#define GREEN "\033[0;32m"
	#define ORANGE "\033[0;33m"
	#define BLUE "\033[0;34m"
	#define PURPLE "\033[0;35m"
	#define CYAN "\033[0;36m"
	#define LIGHTGRAY "\033[0;37m"

	#define DARKGRAY "\033[1;30m"
	#define LIGHTRED "\033[1;31m"
	#define LIGHTGREEN "\033[1;32m"
	#define LIGHTBLUE "\033[1;34m"
	#define LIGHTPURPLE "\033[1;35m"
	#define LIGHTCYAN "\033[1;36m"
	#define YELLOW "\033[1;33m"
	#define WHITE "\033[1;37m"


template <typename T>

class Pair
{
	public:
		Pair();
		~Pair();
		Pair(const Pair &copy);
		Pair &operator=(const Pair &copy);

		Pair(T *a, T *b);

		void sortOrder();
		void sortDisorder();

		void printTabPair();

		T &getA() const;
		T &getB() const;

		bool operator==(const Pair &copy);
		bool operator<=(const Pair &copy);
		bool operator>=(const Pair &copy);
		bool operator<(const Pair &copy);
		bool operator>(const Pair &copy);

	private:

		T *_a;
		T *_b;
};

template <typename T>


std::ostream& operator<<(std::ostream& os, const Pair<T> &data)
{
	os << (data.getA()) << " " << (data.getB());
	return os;
}

template <typename T>
Pair<T>::Pair() : _a(-42), _b(-42)
{}

template <typename T>
Pair<T>::~Pair()
{}

template <typename T>
Pair<T>::Pair(const Pair<T> &copy) : _a(copy._a), _b(copy._b)
{}


template <typename T>
Pair<T> &Pair<T>::operator=(const Pair &copy) 
{
	this->_a = copy._a;	
	this->_b = copy._b;

	return *this;
}

template <typename T>
Pair<T>::Pair(T *a, T *b) : _a(a), _b(b)
{}

template <typename T>
void Pair<T>::sortOrder()
{
	if (this->getA() > this->getB())
	{
		this->_tmp = this->getA();
		this->_a = this->getB();
		this->_b = this->_tmp;
	}
}

template <typename T>
void Pair<T>::sortDisorder()
{
	if ((this->getA()) < (this->getB()))
	{
		// std::cout << GREEN << "SWAP" << std::endl;
		std::swap(this->_a, this->_b);
	}
	
}


template <typename T>
T &Pair<T>::getA() const
{	return *(this->_a);}

template <typename T>
T &Pair<T>::getB() const
{	return *(this->_b);}

template <typename T>
bool Pair<T>::operator==(const Pair &copy)
{
	return (*copy._a == *this->_a);
}

template <typename T>
bool Pair<T>::operator<=(const Pair &copy)
{
	return (*this->_a <= *copy._a);

}

template <typename T>
bool Pair<T>::operator>=(const Pair &copy)
{

	return (*this->_a >= *copy._a);
}

template <typename T>
bool Pair<T>::operator<(const Pair &copy)
{
	return (*this->_a < *copy._a);
}

template <typename T>
bool Pair<T>::operator>(const Pair &copy)
{
	return (*this->_a > *copy._a);
}

#endif