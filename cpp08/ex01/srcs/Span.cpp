/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngriveau <ngriveau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 17:16:09 by ngriveau          #+#    #+#             */
/*   Updated: 2024/01/24 19:04:14 by ngriveau         ###   ########.fr       */
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
}

/* ************************************************************************** */

Span::Span(unsigned int N) : _lenght(N)
{}

/* ************************************************************************** */

void Span::addNumber(int number)
{
}

int Span::shortestSpan()
{
}

int Span::longestSpan()
{
}

unsigned int Span::getLenght()
{	return this->_lenght;	}

void Span::printTab()
{
}
