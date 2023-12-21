#include <iostream>
#include "../Include/Array.hpp"
#include <cstdlib>  // for srand and rand
#include <ctime>    // for time

#define MAX_VAL 10
int main(void)
{
    Array<int> numbers(MAX_VAL);
    int* mirror = new int[MAX_VAL];
    srand(time(NULL));
    for (int i = 0; i < MAX_VAL; i++)
    {
        const int value = rand();
        numbers[i] = value;
        mirror[i] = value;
    }
    std::cout << "SCOPE" << std::endl;
    {
        Array<int> tmp = numbers;
        Array<int> test(tmp);
    }
    std::cout << "Check = " << std::endl;
    for (int i = 0; i < MAX_VAL; i++)
    {
        if (mirror[i] != numbers[i])
        {
            std::cerr << "didn't save the same value!!  " << i << std::endl;
            return 1;
        }
    }
    std::cout << "Try 1" << std::endl;
    try
    {
        std::cout << "numbers[0]";
        numbers[0] = 0;
        std::cout << "OK\nnumbers[-1]";
        numbers[-1] = 0;
        std::cout << "OK\nnumbers[-2]";
        numbers[-2] = 0;
        std::cout << "OK\n";
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    std::cout << "Try 2" << std::endl;
    try
    {
        std::cout << "|MAX - 1| ";
        numbers[MAX_VAL-1] = 42;
        std::cout << "OK\n|MAX| ";
        numbers[MAX_VAL] = 43;
        std::cout << "OK\n";
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    for (int i = 0; i < MAX_VAL; i++)
    {
        std::cout << "numbers[" << i << "] = " << numbers[i];
        numbers[i] = rand();
        std::cout << " -> " << numbers[i] << std::endl;
    }
    delete [] mirror;
    return 0;
}