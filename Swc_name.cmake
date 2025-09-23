# THis File will be used as a navigator through all the SSwc_names so when we add any new SWC we add his name here with his path relative to the Root_Dir path 
# So instead of manully typing the SWC path we just call its name and it will be replaced with the path 

# This is the Cmakevar wich will contain the Path of the Root folder 
set (Root_Dir  ${CMAKE_CURRENT_SOURCE_DIR}) 

# Below will be the Cmake_var which will conatain the Cmake_var containg the path to SWC relative to Root_Dir 

set(CALC_SWC ${Root_Dir}/src/Calc_SWC/)

# Below is the Cmake_variable that will define the path to the main.cpp as the entry point of exuaction and the endpoint of the compilation 

set (main ${Root_Dir}/src/system_start_SWC/main.cpp)

# Below a path for the print_swc relative to the Root_Dir 

set(print_swc ${Root_Dir}/src/print_swc/)


# Set the path to the FreeRTOS kernel submodule
set(FREERTOS_KERNEL_PATH ${Root_Dir}/src/FreeRTOS/)
