/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngriveau <ngriveau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 16:26:29 by ngriveau          #+#    #+#             */
/*   Updated: 2024/02/14 13:22:42 by ngriveau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/RPN.hpp"


int ft_isop(char c)
{
	if (c == '+' || c == '-' || c == '*' || c == '/')
		return 1;
	return 0;
}

long operation(std::deque<std::string>::iterator num1, std::deque<std::string>::iterator num2, std::deque<std::string>::iterator op)
{
	if ((*op)[0] == '+')
		return (std::atol((*num1).c_str())) + (std::atol((*num2).c_str()));
	if ((*op)[0] == '-')
		return (std::atol((*num1).c_str())) - (std::atol((*num2).c_str()));
	if ((*op)[0] == '*')
		return (std::atol((*num1).c_str())) * (std::atol((*num2).c_str()));
	if ((*op)[0] == '/')
		return (std::atol((*num1).c_str())) / (std::atol((*num2).c_str()));
	return -1;
}

void printStack(std::deque<std::string> &deque)
{
	std::deque<std::string>::iterator it = deque.begin();
	std::deque<std::string>::iterator ite = deque.end();

	for (; it != ite ; it++)
	{
		std::cout << *it << " " ;
	}
	std::cout   << std::endl;
}

int findArg(std::deque<std::string> &deque, std::deque<std::string>::iterator &num1, std::deque<std::string>::iterator &num2, std::deque<std::string>::iterator &op)
{
	std::deque<std::string>::iterator it = deque.begin();
	std::deque<std::string>::iterator ite = deque.end();
	int id = 1;
	for (; it != ite ; it++)
	{
		// std::cout << "Is digit " << !!std::isdigit((*it)[0]) << " " << (*it)[0] << " " <<  std::endl;
		std::cout << "(*it).size() " << (*it).size() << " " << *(it) << " " <<  std::endl;
		if (ft_isop((*it)[0]) && (*it).size() == 1)
		{
			// if (id != 3)
				// return -1;
			op = it;
			id++;
			return 0;
		}
		else 
		{
			if (id == 1)
				num1 = it;
			if (id == 2)
				num2 = it;
			id++;
		}
	}
	return -1;
	
}

std::string longToString(long num) {
    std::ostringstream oss;
    oss << num;
    return oss.str();
}

int calc(std::deque<std::string> &deque)
{

	int returnValue;

	// std::cout << "findArg: " <<  returnValue << std::endl;
	
	
	// std::cout << operation(num1, num2, op) << std::endl;
	for (int i = 0; i < 4; i++)
	{
		std::deque<std::string>::iterator num1;
		std::deque<std::string>::iterator num2;
		std::deque<std::string>::iterator op;
		std::cout << "------------" << std::endl;
		printStack(deque);
		returnValue = findArg(deque, num1, num2, op);
		std::cout << "returnValue: " << returnValue << std::endl;
		std::cout << *num1 << " " << *num2 << " " << *op << " " << std::endl;
		*num1 = longToString(operation(num1, num2, op));
		deque.erase(num2);
		deque.erase(op);
		printStack(deque);
	}
	
	return 1;
}

int parsing(std::string str, std::deque<std::string> &deque)
{
	bool space = false;
	std::string tmp;
	for (unsigned long i = 0; i < str.size(); i++)
	{
		if (space && str[i] != ' ')
			return 1;
		if (!space && (!std::isdigit(str[i]) && !ft_isop(str[i])))
			return 1;
		if (!space)
		{
			tmp = str[i];
			deque.push_back(tmp);
		}
		space = !space;
		// std::cout << str[i] << std::endl;
	}	
	return 0;
}


int main(int c, char **v)
{
	std::deque<std::string> deque;
	if (c != 2)
		return 0;
	std::string str(v[1]);
	if (parsing(str, deque))
		return 1;
	printStack(deque);

	calc(deque);
	// printStack(deque);
}