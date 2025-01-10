#include "../inc/ScalarConverter.hpp"

int main(int ac, char **av)
{
    if (ac != 2)
    {
        std::cout << "Usage: ./convert [value to convert]" << std::endl;
        return 1;
    }
    
    ScalarConverter::Convert(av[1]);
    return 0;
} 