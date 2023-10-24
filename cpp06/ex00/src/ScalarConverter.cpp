#include "../Include/ScalarConverter.hpp"
#include <cstdio>

void 	ft_convert_char(char *str)
{
    std::cout << "char:\t" << static_cast<char> (str[1]) << std::endl;
    std::cout << "Int:\t" << static_cast<int> (str[1]) << std::endl;
    std::cout << "Float:\t" << static_cast<float>(str[1]) << std::endl;
    std::cout << "Double:\t" << static_cast<double>(str[1]) << std::endl;
}
void 	ft_convert_int(char *str)
{
	int nbr = ft_atoi(str);
	if (!(31 < nbr && nbr < 127))
		std::cout << "Char:\tNon pritable" << std::endl;
	else
		std::cout << "Char:\t" << static_cast<char>(nbr) << std::endl;		
    std::cout << "Int:\t" << static_cast<int> (nbr) << std::endl;
	std::cout << "Float:\t" << str << ".0f" << std::endl;
	std::cout << "Double:\t" << str << ".0" <<  std::endl;
}
void 	ft_convert_float(char *str)
{
	int nbr = ft_atoi(str);
	if (!(31 < nbr && nbr < 127))
		std::cout << "Char:\tNon pritable" << std::endl;
	else
		std::cout << "Char:\t" << static_cast<char>(nbr) << std::endl;		
    std::cout << "Int:\t" << static_cast<int> (nbr) << std::endl;
	std::cout << "Float:\t" << str << std::endl;
	str[ft_strlen(str)-1] = '\0';
	std::cout << "Double:\t" << str << std::endl;
}
void 	ft_convert_double(char *str)
{
	int nbr = ft_atoi(str);
	if (!(31 < static_cast<char>(nbr) && static_cast<char>(nbr) < 127))
		std::cout << "Char:\tNon pritable" << std::endl;
	else
		std::cout << "Char:\t" << static_cast<char>(nbr) << std::endl;		
    std::cout << "Int:\t" << static_cast<int> (nbr) << std::endl;
	std::cout << "Float:\t" << str << "f" << std::endl;
	std::cout << "Double:\t" << str << std::endl;
}


void ft_convert_ninf(void) {
	std::cout << "Char:\t" << "impossible" << std::endl;		
    std::cout << "Int:\t" << "impossible" << std::endl;
	std::cout << "Float:\t" << "-inff" << std::endl;
	std::cout << "Double:\t" << "-inf" << std::endl;
}

void ft_convert_pinf(void) {
	std::cout << "Char:\t" << "impossible" << std::endl;		
    std::cout << "Int:\t" << "impossible" << std::endl;
	std::cout << "Float:\t" << "inff" << std::endl;
	std::cout << "Double:\t" << "inf" << std::endl;	
}

void ft_convert_nan(void) {
	std::cout << "Char:\t" << "impossible" << std::endl;		
    std::cout << "Int:\t" << "impossible" << std::endl;
	std::cout << "Float:\t" << "nanf" << std::endl;
	std::cout << "Double:\t" << "nan" << std::endl;	
}





void ScalarConverter::convert(char *str)
{
	int id = ft_is_what(str);
	std::cout << "id = " << id << std::endl << std::endl<< std::endl;

	if (id == _Char)
		ft_convert_char(str);
	else if (id == _Int)
		ft_convert_int(str);
	else if (id == _Float)
		ft_convert_float(str);
	else if (id == _Double)
		ft_convert_double(str);
	else if (id == _NInf)
		ft_convert_ninf();
	else if (id == _PInf)
		ft_convert_pinf();
	else if (id == _Nan)
		ft_convert_nan();
	else
		std::cout << "Bad input" << std::endl;
	
}
