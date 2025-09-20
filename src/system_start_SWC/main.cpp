#include <iostream>
#include "calc.hpp"
#include "printing.hpp"
#include "name_space_swc.hpp"
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
    
    
    std::cout << "\n ----------using namespace-------------------------\n";
    space1::printer();    
    std::cout << "\n ----------using namespace spcae 2-------------------------\n";
    space2::name name_obj;
    name_obj.inside_class();
    name_obj.num1=10;
    name_obj.chr='a';
    std::cout <<"\n The number inside the namespaces inside class name is :"<<name_obj.num1<<"\n";
    std::cout <<"\n The character inside the namespaces inside class name is :"<<name_obj.chr<<"\n";
    
    
    






    return 0;
}