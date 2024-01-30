/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngriveau <ngriveau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 17:16:09 by ngriveau          #+#    #+#             */
/*   Updated: 2024/01/30 18:43:57 by ngriveau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Span.hpp"

Span::Span() : _lenght(0)
{}

Span::~Span()
{}

Span::Span(const Span &copy) : _lenght(copy._lenght)
{
	*this = copy;
}

Span &Span::operator=(const Span &copy)
{
	if (this->_lenght != copy._lenght)
		throw std::runtime_error("not the same lenght");
	std::vector<int>::const_iterator begin = copy._vec.begin();
	std::vector<int>::const_iterator end = copy._vec.end();

	this->_vec.clear();
	while (begin != end)
	{
		this->_vec.push_back(*begin);
		begin++;
	}
	return (*this);
}

/* ************************************************************************** */

Span::Span(unsigned long N) : _lenght(N)
{}

/* ************************************************************************** */

void Span::addNumber(int number)
{
	if (this->_vec.size() < this->_lenght)
		this->_vec.push_back(number);
	else
		throw std::runtime_error("can't add more numbers: size max");

}

long long Span::shortestSpan()
{
	if (this->_vec.size() < 2)	
		throw std::runtime_error("bad size (size < 2)");

	int diff = INT_MAX;
	std::vector<int> vec = this->_vec;
	std::sort(vec.begin(), vec.end());
	
	for (std::vector<int>::iterator it = vec.begin(); it != vec.end()-1; it++)
	{
		if (std::abs((*(it+1)) - *(it)) < diff)
			diff = std::abs((*(it+1)) - *(it));
	}
	return (diff);
	
}

long long Span::longestSpan()
{
	if (this->_vec.size() < 2)	
		throw std::runtime_error("bad size (size < 2)");
	std::vector<int> vec = this->_vec;
	
	std::sort(vec.begin(), vec.end());
	return static_cast<long long>(*(--vec.end())) - static_cast<long long>(*(vec.begin()));
}

unsigned long Span::getLenght()
{	return this->_lenght;	}

void Span::printTab()
{
	std::cout << "|";
	for (unsigned long i = 0; i < this->_vec.size(); i++)
	{
		if (i < this->_vec.size() - 1)
			std::cout << this->_vec[i] << ",";
		else 
			std::cout << this->_vec[i];
	}
	std::cout << "|";
	std::cout << std::endl;
}
