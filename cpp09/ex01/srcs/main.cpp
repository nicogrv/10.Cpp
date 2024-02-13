/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngriveau <ngriveau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 16:26:29 by ngriveau          #+#    #+#             */
/*   Updated: 2024/02/13 19:21:05 by ngriveau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/RPN.hpp"


int ft_isop(char c)
{
	if (c == '+' || c == '-' || c == '*' || c == '/')
		return 1;
	return 0;
}

int operation(char num1, char num2, char op)
{
	if (op == '+')
		return (num1-48) + (num2-48);
	if (op == '-')
		return (num1-48) - (num2-48);
	if (op == '*')
		return (num1-48) * (num2-48);
	if (op == '/')
		return (num1-48) / (num2-48);
	return -1;
}

void printStack(std::deque<char> &deque)
{
	std::deque<char>::iterator it = deque.begin();
	std::deque<char>::iterator ite = deque.end();
	for (; it != ite ; it++)
	{
		std::cout << " " << *it;
	}
	std::cout  << "|" << std::endl;
}

int findArg(std::deque<char> &deque, std::deque<char>::iterator &num1, std::deque<char>::iterator &num2, std::deque<char>::iterator &op)
{
	std::deque<char>::iterator it = deque.begin();
	std::deque<char>::iterator ite = deque.end();
	int id = 1;
	for (; it != ite ; it++)
	{
		if (std::isdigit(*it))
		{
			if (id == 1)
				num1 = it;
			if (id == 2)
				num2 = it;
			id++;
		}
		if (ft_isop(*it))
		{
			// if (id != 3)
				// return -1;
			op = it;
			id++;
			return 0;
		}
	}
	return -1;
	
}

int calc(std::deque<char> &deque)
{
	std::deque<char>::iterator num1;
	std::deque<char>::iterator num2;
	std::deque<char>::iterator op;
	for (int i = 0; i < 4; i++)
	{
			
		std::cout << "findArg: " << findArg(deque, num1, num2, op) << " " << operation(*num1, *num2, *op) << std::endl;
		*num1 = operation(*num1, *num2, *op)+48;
		deque.erase(num2);
		deque.erase(op);
		printStack(deque);
	}
	
	return 1;
}

int parsing(std::string str, std::deque<char> &deque)
{
	bool space = false;
	for (unsigned long i = 0; i < str.size(); i++)
	{
		if (space && str[i] != ' ')
			return 1;
		if (!space && (!std::isdigit(str[i]) && !ft_isop(str[i])))
			return 1;
		if (!space)
			deque.push_back(str[i]);
		space = !space;
		// std::cout << str[i] << std::endl;
	}	
	return 0;
}


int main(int c, char **v)
{
	std::deque<char> deque;
	if (c != 2)
		return 0;
	std::string str(v[1]);
	if (parsing(str, deque))
		return 1;
	printStack(deque);

	calc(deque);
	printStack(deque);
}