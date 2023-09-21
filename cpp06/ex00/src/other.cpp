#include <iostream>
#include "../Include/other.hpp"

int ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str && str[i])
		i++;
	return (i);
}

bool ft_is_num(char ch)
{
	if (('0' <= ch && ch <= '9') || ch == '.' || ch == 'f' || ch == '-' || ch == '+')
		return (true);
	return (false);
}

int ft_is_what(char *str)
{
	int i = -1;
	bool point = false;
	bool F = false;
	bool nb = false;

	// if (str == "-inff" || str == "+inff")
	// 	return (_Inff);
	// if (str == "-inf" || str == "+inf")
	// 	return (_Inf);
	if (str && ft_strlen(str) == 3 && str[0] == '\'' && str[ft_strlen(str)-1] =='\'')
		return (_Char);
	if (str[ft_strlen(str)-1] == 'f')
		F = true;
	std::cout << str[ft_strlen(str)-1] << std::endl;
	while (str && str[++i])
	{
		if (('0' <= str[i] && str[i] <= '9'))
			nb = true;
		if (ft_is_num(str[i]) == false)
			return (_Error);
		if (str[i] == '.' && point == false)
			point = true;
		else if (str[i] == '.' && point == true) 
			return (_Error);
		if (str[i] == 'f' && i != ft_strlen(str)-1)
			return (_Error);
		if ((str[i] == '-' || str[i] == '+') && i != 0)
			return (_Error);
		
	}
	std::cout << F << "\t" << point << std::endl;
	if (F && point && nb)
		return (_Float);
	if (!F && !point && nb)
		return (_Int);
	if (!F && point && nb)
		return (_Double);
	return (_Error);
		
}