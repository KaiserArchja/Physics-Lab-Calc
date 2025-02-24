#include "../include/main.hpp"


int main(){
    int func;
    std::cout << "Least Square Method => 1" << std::endl;
    std::cout << "Write function number: ";
    std::cin >> func;
    switch (func)
    {
    case 1:
        LeastSquare();
        break;
    
    default:
        std::cout << "You wrote wrong number!";
        break;
    }
    return 0;
}