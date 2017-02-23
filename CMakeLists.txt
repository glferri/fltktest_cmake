cmake_minimum_required(VERSION 3.5)
project(fltktest)

# version number
set (fltktest_VERSION_MAJOR 0)
set (fltktest_VERSION_MINOR 1)


# I like to have all artifacts inside build
set (PROJECT_BINARY_DIR ${PROJECT_BINARY_DIR}/build)
# I like to put sources under src
set (PROJECT_SOURCE_DIR ${PROJECT_SOURCE_DIR}/src)

# configure a header file to pass some of the CMake settings
# to the source code

configure_file (
    "${PROJECT_SOURCE_DIR}/fltktest_config.h.in"
    "${PROJECT_BINARY_DIR}/fltktest_config.h"
    )

# add the binary tree to the search path for include files
# so that we will find fltktest_config.h
include_directories("${PROJECT_BINARY_DIR}")

#separate artifacts in different dirs 
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR}/bin)

######### DEPENDENCIES ############
find_package(FLTK REQUIRED)
#FIND_PACKAGE(OpenGL REQUIED)

######### OPTIONS ################
option (DUMP_INFO "Show unuseful info" ON)
#we can use options here like this:
#if (DUMP_INFO)
#    cmake commands
#endif (DUMP_INFO)
#
#we can also check in code if we add #cmakedefine DUMP_INFO in project_config.h.in

######### MODULES ################

#main module
include_directories ("${PROJECT_SOURCE_DIR}/main")
add_subdirectory(${PROJECT_SOURCE_DIR}/main)


########## INSTALL ################

#AAA:these go into relative submodules

#  library

#install (TARGETS MathFunctions DESTINATION bin)
#install (FILES MathFunctions.h DESTINATION include)

#  application

install (FILES "${PROJECT_BINARY_DIR}/fltktest_config.h"        
         DESTINATION include)


############# UNINSTALL (OPTIONAL AND NOT SUGGESTED)
# uninstall target
configure_file(
    "${CMAKE_CURRENT_SOURCE_DIR}/cmake_uninstall.cmake.in"
    "${CMAKE_CURRENT_BINARY_DIR}/cmake_uninstall.cmake"
    IMMEDIATE @ONLY)

add_custom_target(uninstall
    COMMAND ${CMAKE_COMMAND} -P ${CMAKE_CURRENT_BINARY_DIR}/cmake_uninstall.cmake)


