/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngriveau <ngriveau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 16:26:29 by ngriveau          #+#    #+#             */
/*   Updated: 2024/01/23 15:46:42 by ngriveau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../inc/ScalarConverter.hpp"

int main(int c, char **v)
{
	if (c == 2)
	{
		ScalarConverter::convert(v[1]);
		return 0;
	}


	std::string nbr;


	std::cout << std::endl << "_____________________________INT______________________________" << std::endl << std::endl;	
	nbr = "0";
	std::cout << std::endl << "----------------------\"" << nbr << "\"--------------------------" << std::endl;	
	ScalarConverter::convert(nbr);

	nbr = "4";
	std::cout << std::endl << "----------------------\"" << nbr << "\"--------------------------" << std::endl;	
	ScalarConverter::convert(nbr);

	nbr = "2147483647";
	std::cout << std::endl << "----------------------\"" << nbr << "\"--------------------------" << std::endl;	
	ScalarConverter::convert(nbr);

	nbr = "2147483648";
	std::cout << std::endl << "----------------------\"" << nbr << "\"--------------------------" << std::endl;	
	ScalarConverter::convert(nbr);

	nbr = "-2147483648";
	std::cout << std::endl << "----------------------\"" << nbr << "\"--------------------------" << std::endl;	
	ScalarConverter::convert(nbr);

	nbr = "-2147483649";
	std::cout << std::endl << "----------------------\"" << nbr << "\"--------------------------" << std::endl;	
	ScalarConverter::convert(nbr);
	std::cout << std::endl << "____________________________FLOAT______________________________" << std::endl << std::endl;	

	nbr = "42f";
	std::cout << std::endl << "----------------------\"" << nbr << "\"--------------------------" << std::endl;	
	ScalarConverter::convert(nbr);

	nbr = "42.12f";
	std::cout << std::endl << "----------------------\"" << nbr << "\"--------------------------" << std::endl;	
	ScalarConverter::convert(nbr);

	nbr = "inff";
	std::cout << std::endl << "----------------------\"" << nbr << "\"--------------------------" << std::endl;	
	ScalarConverter::convert(nbr);

	nbr = "nanf";
	std::cout << std::endl << "----------------------\"" << nbr << "\"--------------------------" << std::endl;	
	ScalarConverter::convert(nbr);

	nbr = "-inff";
	std::cout << std::endl << "----------------------\"" << nbr << "\"--------------------------" << std::endl;	
	ScalarConverter::convert(nbr);

	nbr = "-nanf";
	std::cout << std::endl << "----------------------\"" << nbr << "\"--------------------------" << std::endl;	
	ScalarConverter::convert(nbr);

	std::cout << std::endl << "_____________________________DOUBLE_____________________________" << std::endl << std::endl;	


	nbr = "42.0";
	std::cout << std::endl << "----------------------\"" << nbr << "\"--------------------------" << std::endl;	
	ScalarConverter::convert(nbr);

	nbr = "42.12";
	std::cout << std::endl << "----------------------\"" << nbr << "\"--------------------------" << std::endl;	
	ScalarConverter::convert(nbr);

	nbr = "inf";
	std::cout << std::endl << "----------------------\"" << nbr << "\"--------------------------" << std::endl;	
	ScalarConverter::convert(nbr);

	nbr = "nan";
	std::cout << std::endl << "----------------------\"" << nbr << "\"--------------------------" << std::endl;	
	ScalarConverter::convert(nbr);

	nbr = "-inf";
	std::cout << std::endl << "----------------------\"" << nbr << "\"--------------------------" << std::endl;	
	ScalarConverter::convert(nbr);

	nbr = "-nan";
	std::cout << std::endl << "----------------------\"" << nbr << "\"--------------------------" << std::endl;	
	ScalarConverter::convert(nbr);

	std::cout << std::endl << "_____________________________CHAR_____________________________" << std::endl << std::endl;	


	nbr = "c";
	std::cout << std::endl << "----------------------\"" << nbr << "\"--------------------------" << std::endl;	
	ScalarConverter::convert(nbr);

	nbr = "\"";
	std::cout << std::endl << "----------------------\"" << nbr << "\"--------------------------" << std::endl;	
	ScalarConverter::convert(nbr);

	nbr = "\0";
	std::cout << std::endl << "----------------------\"\\0\"--------------------------" << std::endl;	
	ScalarConverter::convert(nbr);

	nbr = "\n";
	std::cout << std::endl << "----------------------\"\\n\"--------------------------" << std::endl;	
	ScalarConverter::convert(nbr);

	nbr = 127;
	std::cout << std::endl << "----------------------\"" << nbr << "\"--------------------------" << std::endl;	
	ScalarConverter::convert(nbr);

	nbr = 125;
	std::cout << std::endl << "----------------------\"" << nbr << "\"--------------------------" << std::endl;	
	ScalarConverter::convert(nbr);



	std::cout << std::endl << "____________________________SUBJECT_____________________________" << std::endl << std::endl;	


	
	nbr = "0";
	std::cout << std::endl << "----------------------\"" << nbr << "\"--------------------------" << std::endl;	
	ScalarConverter::convert(nbr);

	nbr = "nan";
	std::cout << std::endl << "----------------------\"" << nbr << "\"--------------------------" << std::endl;	
	ScalarConverter::convert(nbr);
	
	nbr = "*";
	std::cout << std::endl << "----------------------\"" << nbr << "\"--------------------------" << std::endl;	
	ScalarConverter::convert(nbr);
}
