project(rpback)
cmake_minimum_required(VERSION 2.8)

include(CheckCXXCompilerFlag)
CHECK_CXX_COMPILER_FLAG("-std=c++11" COMPILER_SUPPORTS_CXX11)
CHECK_CXX_COMPILER_FLAG("-std=c++0x" COMPILER_SUPPORTS_CXX0X)

if(COMPILER_SUPPORTS_CXX11)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
elseif(COMPILER_SUPPORTS_CXX0X)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++0x")
else()
    message(STATUS "The compiler ${CMAKE_CXX_COMPILER} has no C++11 support.")
endif()

include_directories(src)
include_directories(3rdparty)
aux_source_directory(src SRC_LIST)
#aux_source_directory(3rdparty/lua SRC_LIST)
aux_source_directory(3rdparty/micropather SRC_LIST)
aux_source_directory(3rdparty/yaml-cpp SRC_LIST)
aux_source_directory(test SRC_LIST_TEST)

# Main executable
add_executable(${PROJECT_NAME} ${SRC_LIST})

# Testing executable
add_executable(${PROJECT_NAME}_test ${SRC_LIST} ${SRC_LIST_TEST})
set_target_properties(${PROJECT_NAME}_test PROPERTIES
    COMPILE_DEFINITIONS "RPBACK_NO_MAIN")
