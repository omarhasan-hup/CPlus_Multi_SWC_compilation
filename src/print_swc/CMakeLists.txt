# This is the CMakeListst.txt of the print_swc and it will make a static lib of it and make its hpp public to any one link its lib.a
message ("Reached here to excute the CMakeLists for the print_swc >>> \t" ${print_swc} "\t<<<")

add_library(print_swc SHARED

            printing.cpp   
            printing.hpp
            
)

target_include_directories(print_swc PUBLIC ${print_swc})