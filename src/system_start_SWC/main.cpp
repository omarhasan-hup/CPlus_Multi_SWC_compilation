#include <iostream>
#include "calc.hpp"
#include "printing.hpp"
int main ()
{
    int x1=0;
    int x3=10;
    int x4=8;
    auto x2=calc(x3,x4);

    std::cout << "X1= "<< x1 <<"\n";
    std::cout << "X2= "<< x2 <<"\n";
    std::cout << "X3= "<< x3 <<"\n";
    std::cout << "X4= "<< x4 <<"\n";
    
    std::cout << "Using the Print_swc Below \n";

    printing();



    
    






    return 0;
}