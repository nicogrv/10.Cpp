/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngriveau <ngriveau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 12:49:58 by ngriveau          #+#    #+#             */
/*   Updated: 2024/02/21 14:13:21 by ngriveau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/BitcoinExchange.hpp"

int	ft_atoi_pt2(const char *str, int i, long nb, int signe)
{
	int	index;

	index = i;
	while ('0' <= str[i] && str[i] <= '9')
		nb = nb * 10 + str[i++] - 48;
	if ((i - index) > 15)
		return (-1);
	if (str[i] == '\0' && -2147483648 <= (nb * signe)
		&& (nb * signe) <= 2147483647 && (i - index) < 15)
		return (nb);
	
	return (-1);
}

int	ft_atoi(const char *str)
{	
	int		i;
	int		signe;
	long	nb;

	signe = 1;
	i = 0;
	nb = 0;
	if (!str[i])
		return (-1);
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
		return (-1);
	return (ft_atoi_pt2(str, i, nb, signe));
}



int calcDate(int day, int month, int year)
{
	int calcDay = day;
	day = 1;
	while (true)
	{

		// std::cout << day << " " << month << " " << year << "(" << calcDay << ")" << std::endl;
		if (day == 1 && month == 1 && year == 0)
			return calcDay;
		if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12)
		
			calcDay += 31;
		if (month == 4 || month == 6 || month == 9 || month == 11)
			calcDay += 30;
		if (month == 2 && !!(year%4))
			calcDay += 28;
		if (month == 2 && !(year%4))
			calcDay += 29;
		month--;
		if (month == 0)
		{
			month = 12;
			year--;
		}
	}
}

int convertDate(std::string date)
{
	int tir = 2;

	std::string day;
	std::string month;
	std::string year;
	if (!std::isdigit(date[0]) || !std::isdigit(date[date.length()-1]))
		return -1;
	for (unsigned long i = 0; i < date.length(); i++) {
		if (!std::isdigit(date[i]) && date[i] != '-')
			return -1;
		if (0 < i && date[i] == '-' && !std::isdigit(date[i-1]))
			return -1;
		if (date[i] == '-')
			tir--;
		else if (tir == 2)
			year  += date[i];
		else if (tir == 1)
			month += date[i];
		else if (tir == 0)
			day += date[i];
	}
	int nbDay = ft_atoi(day.c_str());
	int nbMonth = ft_atoi(month.c_str());
	int nbYear = ft_atoi(year.c_str());

	if (nbDay < 1 || nbMonth < 1 || nbYear < 0 || tir || 12 < nbMonth)
		return -1;
	if (((nbMonth == 1 || nbMonth == 3 || nbMonth == 5 || nbMonth == 7 || nbMonth == 8 || nbMonth == 10 || nbMonth == 12) && 31 < nbDay))
		return -1;
	if (((nbMonth == 4 || nbMonth == 6 || nbMonth == 9 || nbMonth == 11) && 30 < nbDay))
		return -1;
	if ((nbMonth == 2 && nbYear%4 && 28 < nbDay))
		return -1;
	if ((nbMonth == 2 && !nbYear%4 && 29 < nbDay))
		return -1;
	return calcDate(nbDay, nbMonth, nbYear);
}

int ft_fill(std::map<int, float> &map, std::string &firstDate, std::string &lastDate)
{
	std::string line;
	int index = 0;
	size_t pos;
	std::ifstream file("./data/data.csv");	
	if (!file.is_open())
		return 1;
	getline(file, line);
	while(getline(file, line))
	{
		
		if (!index)
			firstDate = line.substr(0 ,line.find(','));
		pos = line.find(',');
		map[convertDate(line.substr(0 ,line.find(',')))] = std::atof(line.substr(pos + 1).c_str());
		lastDate = line.substr(0 ,line.find(','));
		index ++;
	}
	file.close();
	return 0;
}


int ft_init(std::map<int, float> &map, std::string &firstDate, std::string &lastDate)
{
	if (ft_fill(map, firstDate, lastDate))
		return 1;
	unsigned int end = (--map.end())->first;
	for (unsigned int i = 0; i <= end; i++)
		map[i] = -1;
	if (ft_fill(map, firstDate, lastDate))
		return 1;
	return 0;
}

int ft_find(char *v, std::map<int, float> &map, int firstDate, int lastDate)
{
	size_t pos;
	std::string line;
	std::ifstream file(v);
	if (!file.is_open())
	{
		std::cout << "Can't open data file" << std::endl;
		return 1;
	}
	getline(file, line);
	while(getline(file, line))
	{
		pos = line.find('|');
		float q = std::atof(line.substr(pos+1).c_str());
		if (pos == std::string::npos || (0 < pos && (line[pos-1] != ' ' || line[pos+1] != ' ')))
			std::cout << "Error: bad input => " << line << std::endl;
		else if (1000 < q)
			std::cout << "Error: too large a number." << std::endl;
		else if (q < 0)
			std::cout << "Error: not a positive number." << std::endl;
		else if (convertDate(line.substr(0, pos-1)) == -1)
			std::cout << "Error: bad date => " << line << std::endl;
		else
		{
			int end = (--map.end())->first;
			
			if (end < convertDate(line.substr(0, pos-1)))
				std::cout << line.substr(0, pos-1) << " => " << q << " = " << q*map[end] << std::endl;
			else if (map[convertDate(line.substr(0, pos-1))] != -1)
				std::cout << line.substr(0, pos-1) << " => " << q << " = " << q*map[convertDate(line.substr(0, pos-1))] << std::endl;
			else
			{
				int i = 1;
				while(1)
				{
					if (convertDate(line.substr(0, pos-1))-i < firstDate)
					{
						std::cout << line.substr(0, pos-1) << " => " << q << " = " << q*map[firstDate] << std::endl;
						break;	
					}
					if (lastDate < convertDate(line.substr(0, pos-1))+i)
					{
						std::cout << line.substr(0, pos-1) << " => " << q << " = " << q*map[lastDate] << std::endl;
						break;
					}
					if (map[convertDate(line.substr(0, pos-1))-i] != -1)
					{
						std::cout << line.substr(0, pos-1) << " => " << q << " = " << q*map[convertDate(line.substr(0, pos-1))-i] << std::endl;
						// std::cout << q << "  " << map[convertDate(line.substr(0, pos-1))-i] << std::endl;
						break;	
					}
					if (map[convertDate(line.substr(0, pos-1))+i] != -1)
					{
						std::cout << line.substr(0, pos-1) << " => " << q << " = " << q*map[convertDate(line.substr(0, pos-1))+i] << std::endl;
						// std::cout << q << "  " << map[convertDate(line.substr(0, pos-1))+i] << std::endl;
						break;	
					}
					std::cout << map.size() << std::endl;
					i++;
				}
				// std::cout << "|" << map[convertDate(line.substr(0, pos-1))] << "|" << std::atof(line.substr(pos+1).c_str()) << std::endl;
			}				
		}
	}		
	return 1;
}


int	BitcoinExchange(char *v)
{
	std::map<int, float> map;
	std::string firstDate;
	std::string lastDate;
	
	if (ft_init(map, firstDate, lastDate))
		return 1;
	ft_find(v, map, convertDate(firstDate), convertDate(lastDate));
	return 0;
}