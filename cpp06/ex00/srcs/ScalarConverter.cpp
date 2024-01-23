/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngriveau <ngriveau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 16:41:46 by ngriveau          #+#    #+#             */
/*   Updated: 2024/01/23 16:03:54 by ngriveau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ScalarConverter.hpp"

ScalarConverter::ScalarConverter()
{
	
}

ScalarConverter::~ScalarConverter()
{
	
}

ScalarConverter::ScalarConverter(const ScalarConverter &copy)
{
	*this = copy;
}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &copy)
{
	(void) copy;
	return (*this);
}

/* ************************************************************************** */




int	ft_isInt(const char *str)
{	
	int		i = 0;
	int		signe = 1;
	long	nb = 0;
	int	index;

	if (!str[i])
		return (0);
	while (('\t' <= str[i] && str[i] <= '\r') || (str[i] == ' '))
		i++;
	if (str[i] == '+')
		i++;
	else if (str[i] == '-')
	{
		i++;
		signe = -signe;
	}
	if (str[i] == '\0')
		return (0);
	index = i;
	while ('0' <= str[i] && str[i] <= '9')
		nb = nb * 10 + str[i++] - 48;
	if ((i - index) > 15)
		return (0);
	if (str[i] == '\0' && -2147483648 <= (nb * signe)
		&& (nb * signe) <= 2147483647 && (i - index) < 15)
		return (1);
	return (0);
}

//0->ERROR 1->INT 2->FLOAT 3->DOUBLE 4->CHAR
int getIdString(std::string str)
{
	char *stopString;
	
	std::ostringstream convertisseur;
	if (str.length() == 1 && !ft_isInt(str.c_str()))
		return 4;
	double nbr = strtod(str.c_str(), &stopString);
	int lenStopString = static_cast <std::string>(stopString).length();
	if (1 < lenStopString)
		return 0;
	if (lenStopString == 1 && stopString[0] == 'f')
		return 2;
	if (str.find('.') != std::string::npos || std::isnan(nbr) || std::isinf(nbr))
		return 3;
	if (ft_isInt(str.c_str()))
		return 1;
	return 0;
}


std::string floatNeedZero(float nbr)
{
	std::ostringstream nbrSting;
	nbrSting << nbr;
	std::string s(nbrSting.str());
	if (s.find('.') == std::string::npos && !std::isnan(nbr) && !std::isinf(nbr))
		return (".0");
	return("");

}

void impossibleInt(std::string str, double nbr)
{
	(void) str;
	if (nbr < -2147483648 || 2147483647 < nbr - 1 || std::isnan(nbr) || static_cast<int>(nbr) != nbr)
		std::cout << "int    : impossible" << std::endl;
	else 
		std::cout << "int    : " << static_cast<int>(nbr) << std::endl;
}

void	convertInt(std::string str)
{
	char *null;
	double nbr = strtod(str.c_str(), &null);
	std::string addZero = floatNeedZero(nbr);
	
	if (nbr < 0 || 127 < nbr || std::isnan(nbr))
		std::cout << "char   : impossible" << std::endl;
	else if (!isprint(nbr))
		std::cout << "char   : Non displayable" << std::endl;
	else
		std::cout << "char   : " << static_cast<char>(nbr) << std::endl;
	impossibleInt(str, nbr);
	std::cout << "float  : " << static_cast<float>(nbr) << addZero << "f" << std::endl;
	std::cout << "double : " << static_cast<double>(nbr) << addZero << std::endl;
}


void	convertFloat(std::string str)
{
	char *null;
	float nbr = strtof(str.c_str(), &null);
	std::string addZero = floatNeedZero(nbr);
	
	if (nbr < 0 || 127 < nbr || std::isnan(nbr))
		std::cout << "char   : impossible" << std::endl;
	else if (!isprint(nbr))
		std::cout << "char   : Non displayable" << std::endl;
	else
		std::cout << "char   : " << static_cast<char>(nbr) << std::endl;
	impossibleInt(str, nbr);
	std::cout << "FLOAT  : " << std::fixed <<  nbr << addZero << "f" << std::endl;
	std::cout << "double : " << static_cast<double>(nbr) << addZero << std::endl;
}

void	convertDouble(std::string str)
{
	char *null;
	double nbr = strtod(str.c_str(), &null);
	
	if (nbr < 0 || 127 < nbr || std::isnan(nbr))
		std::cout << "char   : impossible" << std::endl;
	else if (!isprint(nbr))
		std::cout << "char   : Non displayable" << std::endl;
	else
		std::cout << "char   : " << static_cast<char>(nbr) << std::endl;
	impossibleInt(str, nbr);
	std::cout << "Float  : " << static_cast<float>(nbr)  << "f" << std::endl;
	std::cout << "DOUBLE : " << nbr << std::endl;
}

void	convertChar(std::string str)
{
	std::string addZero = "";
	if (str.find('.') == std::string::npos)
		addZero = ".0";
	if (!isprint(str.c_str()[0]))
		std::cout << "CHAR   : Non displayable" << std::endl;
	else
		std::cout << "CHAR   : " << str.c_str()[0] << std::endl;
	std::cout << "int    : " << static_cast<int>(str.c_str()[0]) << std::endl;
	std::cout << "float  : " << static_cast<float>(str.c_str()[0]) << addZero << "f" << std::endl;
	std::cout << "double : " << static_cast<double>(str.c_str()[0]) << addZero << std::endl;
}



void ScalarConverter::convert(std::string str)
{
	// std::cout <<  "Str = " << str << std::endl;
	int code = getIdString(str);
	switch (code)
	{
	case 1:
		convertInt(str);
		break;
	case 2:
		convertFloat(str);
		break;
	case 3:
		convertDouble(str);
		break;
	case 4:
		convertChar(str);
		break;
	
	default:
		std::cout << "Error bad input"<< std::endl;
		return;
	}
}