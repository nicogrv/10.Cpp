/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngriveau <ngriveau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 12:49:58 by ngriveau          #+#    #+#             */
/*   Updated: 2024/02/14 14:10:18 by ngriveau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/RPN.hpp"

int ft_isop(char c)
{
	if (c == '+' || c == '-' || c == '*' || c == '/')
		return 1;
	return 0;
}

long operation(int num1, int num2, char op)
{
	if (op == '+')
		return num1 + num2;
	if (op == '-')
		return num1 - num2;
	if (op == '*')
		return num1 * num2;
	if (op == '/')
		return num1 / num2;
	return -1;
}

void printStack(std::stack<int> stack)
{
	return ;
	unsigned long i = 0;
	std::cout << "-=-STACK-=-  ";
	while (i < stack.size())
	{
		std::cout << stack.top() << " ";
		stack.pop();
	}
	std::cout << std::endl;
}


int calcul(std::string str, std::stack<int> &stack)
{
	bool space = false;
	int num1;
	int num2;
	for (unsigned long i = 0; i < str.size(); i++)
	{
		if (space && str[i] != ' ')
			return 1;
		if (!space && (!std::isdigit(str[i]) && !ft_isop(str[i])))
			return 1;
		if (!space)
		{
			if(!ft_isop(str[i]))
				stack.push(str[i]-48);
			else
			{
				printStack(stack);
				if (stack.size() < 2)
					return -1;
				num2 = stack.top();
				stack.pop();
				num1 = stack.top();
				stack.pop();
				stack.push(operation(num1, num2, str[i]));
			}
		}
		space = !space;
	}	
	return 0;
}

int RPN(std::string str)
{
	std::stack<int> stack;
	if (calcul(str, stack) || stack.size() != 1)
	{
		std::cout << "Error input" << std::endl;
		return 1;
	}
	std::cout << stack.top() << std::endl;
	return 0;
}

