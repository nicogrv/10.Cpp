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


int	ft_strcmp(const char *s1, const char *s2)
{
	size_t	i;

	i = 0;
	if (!s1 || !s2)
		return -42;
	while (s1[i] || s2[i])
	{
		if (s1[i] != s2[i])
			return (0);
		i++;
	}
	return (1);
}



int ft_is_what(char *str)
{
	int i = -1;
	bool point = false;
	bool F = false;
	bool nb = false;

	if (ft_strcmp("-inff", str) || ft_strcmp("-inf", str))
		return (_NInf);
	if (ft_strcmp("+inff", str) || ft_strcmp("+inf", str) || ft_strcmp("inf", str) || ft_strcmp("inff", str))
		return (_PInf);
	if (ft_strcmp("nan", str) || ft_strcmp("nanf", str))
		return (_Nan);
	if (str && ft_strlen(str) == 3 && str[0] == '\'' && str[ft_strlen(str)-1] =='\'')
		return (_Char);
	if (str[ft_strlen(str)-1] == 'f')
		F = true;
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
	if (F && point && nb)
		return (_Float);
	if (!F && !point && nb)
		return (_Int);
	if (!F && point && nb)
		return (_Double);
	return (_Error);
		
}




int	ft_atoi(char *str)
{
	int	i;
	int	signe;
	int	nb;

	signe = 1;
	i = 0;
	nb = 0;
	while (('\t' <= str[i] && str[i] <= '\r') || (str[i] == ' '))
		i++;
	if (str[i] == '+')
		i++;
	else if (str[i] == '-')
	{
		i++;
		signe = -signe;
	}
	while ('0' <= str[i] && str[i] <= '9')
	{
		nb = nb * 10 + str[i] - 48;
		i++;
	}
	return (nb * signe);
}