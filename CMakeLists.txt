cmake_minimum_required(VERSION 3.10) # This is the minimum required cmake version to genrate the cmake build environemnt for your project

project(cplus) #This is the project name 

set(CMAKE_CXX_STANDARD 17) #USe the c++ standards for 17 release during compilation 

# Make a Cmake_variabe that holds the Root Dir so we could build relative dirs to it
include(Swc_name.cmake)
include(linked_libs.cmake)


# Below we will add the source folders to be compiled from cpp to obj if it ill be used to cimpile file by file 
# set( SOURCES
#     src/main.cpp
# )

# Now we will try the methdology of compiling each SWC alone and make them as a tatic lib then link them all to the main and make an exutable 
add_subdirectory(${CALC_SWC})
add_subdirectory(${print_swc})

message ("The Root_Dir as a Camke varible will be = " ${Root_Dir})
message ("\n Here is the List of the staticaly Linked libs to the main.cpp " ${Linked_libs}"\n")

#Gnerate the exutable bin "Native compilation" from compiling the SOURCES
add_executable(cpp_comlation ${main})
target_link_libraries(cpp_comlation ${Linked_libs} )

