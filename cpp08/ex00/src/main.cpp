#include "../Include/easyfind.hpp"
int main() {
	{
		std::vector<int> monVecteur;

		monVecteur.push_back(1);
		monVecteur.push_back(2);
		monVecteur.push_back(3);
		monVecteur.push_back(42);
		std::cout << easyfind(monVecteur, 1) << std::endl;
		std::cout << easyfind(monVecteur, 42) << std::endl;
		std::cout << easyfind(monVecteur, 15) << std::endl;
	}
	std::cout << std::endl;
	{
		std::vector<int> monVecteur;

		std::cout << easyfind(monVecteur, 3) << std::endl;
	} 
	return 0;
}