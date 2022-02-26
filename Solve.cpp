#include <iostream>
#include"MagicSquare.hpp"

int main() {
    std::cout << "Enter a square size: ";
    int value;
    std::cin >> value;
    
    std::vector<std::vector<int> > square(value);
    
    std::cout << "Enter square format: "<< "\n";
    std::cin >> square;

    return 0;
}
