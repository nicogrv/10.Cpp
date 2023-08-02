#include <fstream>
#include <iostream>
#include <string>
#include <stdlib.h>

void ft_search(char **av)
{
	std::ifstream infile(av[1]);
	if (!infile.is_open()) 
	{
		std::cout << "Error open infile" <<std::endl;
		exit(1);
	}
	std::string filename = av[1];
	std::ofstream outfile(filename.append(".replace").c_str());
	std::string s1 = av[2];
	std::string s2 = av[3];
	size_t oc = 0;

	if (s1.compare("") == 0)
	{
		std::cout << "S1 do not void" <<std::endl;
		exit(1);
	}
	if (!outfile.is_open()) 
	{
		std::cout << "Error open outfile" <<std::endl;
		exit(1);
	}
	std::string line;
	while (std::getline(infile, line)) 
	{
		oc = 0;
		while (line.substr(oc, line.length()).find(s1) != std::string::npos)
		{
			oc += line.substr(oc, line.length()).find(s1);
			line.erase(oc, s1.length());
			line.insert(oc, s2);
			std::cout << line << std::endl;
			oc++;
			
		}
		outfile << line << std::endl;
	}
	infile.close();
	return ;
}

int main(int c, char **av) 
{
	if (c != 4)
		std::cout << "./ex04 inFile S1 S2";
	else
		ft_search(av);
	return (0);
}
