#include <fstream>
#include <iostream>
#include <string>

// void ft_search()
// {
// 	    std::ifstream file("./test.txt");

//     if (file.is_open()) {
//         std::string line;
//         while (std::getline(file, line)) {
//             std::cout << line << std::endl;
	
// 			size_t found = line.find("a");
// 			if (found != std::string::npos)
//     			std::cout << "First occurrence is " << found << std::endl;
//         }

//         file.close();
//     } else {
//         std::cout << "Impossible d'ouvrir le fichier." << std::endl;
//     }

//     return 0;
// }







int main(int c, char **av) 
{
	(void) av;
	if (c != 4)
		std::cout << "./ex04 FILE S1 S2";
	
	return (0);
}
