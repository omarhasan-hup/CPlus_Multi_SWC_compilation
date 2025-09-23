# This is the CMakeListst.txt of the Free_Rtos SWC and it will make a static lib of it and make its hpp public to any one link its lib.a
message ("Reached here to excute the CMakeLists for the print_swc >>> \t" ${FREERTOS_KERNEL_PATH} "\t<<<")

# 2. Check if the FreeRTOS Kernel path is valid
if(NOT EXISTS "${FREERTOS_KERNEL_PATH}/CMakeLists.txt")
    message(FATAL_ERROR "FreeRTOS-Kernel not found at ${FREERTOS_KERNEL_PATH}. Please check the submodule path.")
endif()

# 3. Set the FreeRTOS port. For WSL (and other Linux/macOS), GCC_POSIX is the correct port.
set(FREERTOS_PORT GCC_POSIX CACHE STRING "FreeRTOS port")
message(STATUS "Using FreeRTOS Port: ${FREERTOS_PORT}")

# 4. Select a heap implementation. heap_4 is a good general-purpose choice.
set(FREERTOS_HEAP 4 CACHE STRING "FreeRTOS heap implementation") 
message(STATUS "Using FreeRTOS Heap: ${FREERTOS_HEAP}")



# 5. Provide FreeRTOSConfig.h.
#    This example assumes you have a `config/FreeRTOSConfig.h` file in your project root.
add_library(freertos_config INTERFACE)
target_include_directories(freertos_config INTERFACE
    "${Root_Dir}/"
)

# 6. Add the FreeRTOS kernel as a subdirectory. This creates the 'freertos_kernel' target.
add_subdirectory(FreeRTOS-Kernel)