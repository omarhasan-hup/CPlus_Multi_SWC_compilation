message("Reached here for building the Calc_SWC in the path >>>\t" ${CALC_SWC} "\t<<<")

# The below command of Cmake it will generate a seperae build enviromnet for this spesfic dir CALC_SWC and build it and make aof it a static lib 
add_library( Calc_SWC SHARED calc.cpp calc.hpp)

target_include_directories(Calc_SWC PUBLIC ${CALC_SWC} )