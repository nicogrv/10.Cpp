/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Pair.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngriveau <ngriveau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 14:47:48 by ngriveau          #+#    #+#             */
/*   Updated: 2024/02/19 15:37:26 by ngriveau         ###   ########.fr       */
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

		Pair(T &a, T &b);

		void sortOrder();
		void sortDisorder();

		T getA() const;
		T getB() const;

		bool operator==(const Pair &copy);
		bool operator<=(const Pair &copy);
		bool operator>=(const Pair &copy);
		bool operator<(const Pair &copy);
		bool operator>(const Pair &copy);

	private:

		T &_a;
		T &_b;

		T _tmp;
};

template <typename T>
std::ostream& operator<<(std::ostream& os, const Pair<T> &data)
{
	os << "A: " << data.getA() << " B: " << data.getB() << std::endl;
	return os;
}

template <typename T>
Pair<T>::Pair() : _a(_tmp), _b(_tmp)
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
Pair<T>::Pair(T &a, T &b) : _a(a), _b(b)
{}

template <typename T>
void Pair<T>::sortOrder()
{
	if (this->getA() > this->getB())
	{
		this->_tmp = this->_a;
		this->_a = this->_b;
		this->_b = this->_tmp;
	}
}

template <typename T>
void Pair<T>::sortDisorder()
{
	if (this->getA() < this->getB())
	{
		std::cout << "coucou swan" << '\n';
		char	tmp_a[sizeof(T)];
		char	tmp_b[sizeof(T)];

		std::cout << "a: ";
		for (size_t i = 0; i < sizeof(T); i++)
		{
			std::cout << static_cast<int>((reinterpret_cast<char *>( reinterpret_cast<void *>(&this->_a) ))[i]);
		}
		std::cout << '\n';
		std::cout << "b: ";
		for (size_t i = 0; i < sizeof(T); i++)
		{
			std::cout <<  static_cast<int>((reinterpret_cast<char *>( reinterpret_cast<void *>(&this->_b) ))[i]);
		}
		std::cout << '\n';

		for (size_t i = 0; i < sizeof(T); i++)
		{
			tmp_a[i] = (reinterpret_cast<char *>( reinterpret_cast<void *>(&this->_a) ))[i];
			tmp_b[i] = (reinterpret_cast<char *>( reinterpret_cast<void *>(&this->_b) ))[i];
		}

		for (size_t i = 0; i < sizeof(T); i++)
		{
			(reinterpret_cast<char *>( reinterpret_cast<void *>(&this->_a) ))[i] = tmp_b[i];
			(reinterpret_cast<char *>( reinterpret_cast<void *>(&this->_b) ))[i] = tmp_a[i];
		}
		
		std::cout << "tmp_a: ";
		for (size_t i = 0; i < sizeof(T); i++)
		{
			std::cout << static_cast<int>(tmp_a[i]);
		}
		std::cout << '\n';
		std::cout << "tmp_b: ";
		for (size_t i = 0; i < sizeof(T); i++)
		{
			std::cout << static_cast<int>(tmp_b[i]);
		}
		std::cout << '\n';

		std::cout << "a: ";
		for (size_t i = 0; i < sizeof(T); i++)
		{
			std::cout << static_cast<int>((reinterpret_cast<char *>( reinterpret_cast<void *>(&this->_a) ))[i]);
		}
		std::cout << '\n';
		std::cout << "b: ";
		for (size_t i = 0; i < sizeof(T); i++)
		{
			std::cout <<  static_cast<int>((reinterpret_cast<char *>( reinterpret_cast<void *>(&this->_b) ))[i]);
		}
		std::cout << '\n';
	}
	
}

template <typename T>
T Pair<T>::getA() const
{	return this->_a;}

template <typename T>
T Pair<T>::getB() const
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