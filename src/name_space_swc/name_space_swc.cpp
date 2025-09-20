#include <iostream>
#include "name_space_swc.hpp"

//As the .hpp file has the decleration of the namespace called space1 with the declertion of the insaide function nad the int now we will make the defination of those 

void space1::printer()
{
    std::cout << "\n This is the usage of the function printer inside the namespace caled space1 \n";
    
}

// As the hpp we will now define the other namespace space2
void space2::name::inside_class()
{
    std::cout <<"\n This is the print insdie the Class in the namespace \n";
}

