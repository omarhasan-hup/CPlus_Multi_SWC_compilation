cmake_minimum_required(VERSION 3.15)

project(cplus) #This is the project name 

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Make a Cmake_variabe that holds the Root Dir so we could build relative dirs to it
include(Swc_name.cmake)
include(linked_libs.cmake)





# Now we will try the methdology of compiling each SWC alone and make them as a tatic lib then link them all to the main and make an exutable 
add_subdirectory(${CALC_SWC})
add_subdirectory(${print_swc})
add_subdirectory(${FREERTOS_KERNEL_PATH})


message ("The Root_Dir as a Camke varible will be = " ${Root_Dir})
message ("\n Here is the List of the staticaly Linked libs to the main.cpp " ${Linked_libs}"\n")


#Gnerate the exutable bin "Native compilation" from compiling the SOURCES
add_executable(cpp_compilation ${main})

# For the POSIX port, we need to link with pthreads
set(PLATFORM_SPECIFIC_LIBS "")
if(FREERTOS_PORT STREQUAL "GCC_POSIX")
    find_package(Threads REQUIRED)
    set(PLATFORM_SPECIFIC_LIBS Threads::Threads)
endif()

target_link_libraries(cpp_compilation ${Linked_libs} ${PLATFORM_SPECIFIC_LIBS})