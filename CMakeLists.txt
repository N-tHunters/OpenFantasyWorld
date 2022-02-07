cmake_minimum_required(VERSION 3.10)
project(OpenFantasyWorld)

option (FORCE_COLORED_OUTPUT "Always produce ANSI-colored output (GNU/Clang only)." TRUE)
if (${FORCE_COLORED_OUTPUT})
    if ("${CMAKE_CXX_COMPILER_ID}" STREQUAL "GNU")
       add_compile_options (-fdiagnostics-color=always)
    elseif ("${CMAKE_CXX_COMPILER_ID}" STREQUAL "Clang")
       add_compile_options (-fcolor-diagnostics)
    endif ()
endif ()

# Add source files
file(GLOB_RECURSE SOURCE_FILES
  ${CMAKE_SOURCE_DIR}/src/*.cpp)

# Add header files
file(GLOB_RECURSE HEADER_FILES
  ${CMAKE_SOURCE_DIR}/src/*.hpp)

include_directories(${CMAKE_SOURCE_DIR}/src)

add_executable(${PROJECT_NAME}
  ${CMAKE_SOURCE_DIR}/src/main.cpp
  ${HEADER_FILES}
  ${SOURCE_FILES})

set(CMAKE_CXX_FLAGS, "${CMAKE_CXX_FLAGS} -Wall -g")
