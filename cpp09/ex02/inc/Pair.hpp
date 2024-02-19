/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Pair.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngriveau <ngriveau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 14:47:48 by ngriveau          #+#    #+#             */
/*   Updated: 2024/02/19 16:08:07 by ngriveau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PAIR_HPP
	#define PAIR_HPP
	#include <vector>
	#include <iostream>

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

		T *getA() const;
		T *getB() const;

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
	os << "A: " << *(data.getA()) << " B: " << *(data.getB()) << std::endl;
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
	std::cout << "copy: " << copy << std::endl;
	this->_a = copy._a;	
	this->_b = copy._b;
	std::cout << "this: " << *this << std::endl;

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
	std::cout << *this << std::endl;
	if (this->getA() < this->getB())
	{
		std::cout << "ici\n";
		std::swap(*this->_a, *this->_b);
	}
	std::cout << *this << std::endl << std::endl << std::endl;
	
}

template <typename T>
T *Pair<T>::getA() const
{	return this->_a;}

template <typename T>
T *Pair<T>::getB() const
{	return this->_b;}

template <typename T>
bool Pair<T>::operator==(const Pair &copy)
{
	return (copy._a == this->_a);
}

template <typename T>
bool Pair<T>::operator<=(const Pair &copy)
{
	return (this->_a <= copy._a);

}

template <typename T>
bool Pair<T>::operator>=(const Pair &copy)
{

	return (this->_a >= copy._a);
}

template <typename T>
bool Pair<T>::operator<(const Pair &copy)
{
	std::cout << "check" << !!(this->_a < copy._a) << "\n";
	return (this->_a < copy._a);
}

template <typename T>
bool Pair<T>::operator>(const Pair &copy)
{

	return (this->_a > copy._a);
}

#endif