#include "../Include/ScalarConverter.hpp"
#include <cstdio>



void 	ft_convert_char(char *str)
{
    std::cout << "Char:\t" << str[1] << std::endl;
    std::cout << "Int:\t" << static_cast<int>(str[1]) << std::endl;
    std::cout << "Float:\t" << static_cast<float>(str[1]) << std::endl;
    std::cout << "Double:\t" << static_cast<double>(str[1]) << std::endl;
}
void 	ft_convert_int(char *str)
{
	std::string oui = str;
	
	int test = *(oui.c_str());
	std::cout << test << std::endl;
}
void 	ft_convert_float(char *str)
{
	(void) str;
}
void 	ft_convert_double(char *str)
{
	(void) str;
}



void ScalarConverter::convert(char *str)
{
	int id = ft_is_what(str);
	std::cout << id << std::endl;

	if (id == 0)
		std::cout << "Bad input" << std::endl;
	if (id == 1)
		ft_convert_char(str);
	if (id == 2)
		ft_convert_int(str);
	if (id == 3)
		ft_convert_float(str);
	if (id == 4)
		ft_convert_double(str);

	
}
