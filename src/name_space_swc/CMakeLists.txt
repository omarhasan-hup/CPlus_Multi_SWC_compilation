message("Reached here for building the name_space_swc in the path >>>\t" ${name_space_swc} "\t<<<")

# The below command of Cmake it will generate a seperae build enviromnet for this spesfic dir name_space_swc and build it and make aof it a static lib 
add_library( name_space_swc SHARED name_space_swc.cpp name_space_swc.hpp)

target_include_directories(name_space_swc PUBLIC ${name_space_swc} )