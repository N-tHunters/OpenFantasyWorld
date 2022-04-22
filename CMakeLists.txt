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
  ${CMAKE_SOURCE_DIR}/include/*.hpp)

include_directories(${CMAKE_SOURCE_DIR}/include)
include_directories(${CMAKE_SOURCE_DIR}/thirdparty)
link_directories(${CMAKE_SOURCE_DIR}/thirdparty)

add_executable(${PROJECT_NAME}
  ${CMAKE_SOURCE_DIR}/src/main.cpp
  ${HEADER_FILES}
  ${SOURCE_FILES})

# Find required packages and libraries
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/")
# OpenGL
find_package(OpenGL REQUIRED)

# GLM
find_package(GLM REQUIRED)
message(STATUS "GLM included at ${GLM_INCLUDE_DIR}")

# GLFW
find_package(GLFW3 REQUIRED)
message(STATUS "GLFW3 included at ${GLFW3_INCLUDE_DIR}")
message(STATUS "GLFW3 library found at ${GLFW3_LIBRARY}")

# STB_IMAGE
find_package(STB_IMAGE REQUIRED)
message(STATUS "STB_IMAGE included at ${STB_IMAGE_INCLUDE_DIR}")

# GLEW
find_package(GLEW)
if(NOT GLEW_FOUND)
  message(STATUS "GLEW is not found by default script, setting it manually (works for Windows only)")
  set(GLEW_LIBRARY "${CMAKE_SOURCE_DIR}/lib/glew32.lib")
endif()

if (NOT WIN32)
  target_link_libraries(${PROJECT_NAME} GLEW::GLEW)
endif()

# Assimp
find_package(ASSIMP REQUIRED)
message(STATUS "ASSIMP included at ${GLFW3_INCLUDE_DIR}")

set(LIBS
  ${GLFW3_LIBRARY}
  ${OPENGL_LIBRARY}
  ${GLEW_LIBRARY}
  ${ASSIMP_LIBRARIES}
  ${STB_IMAGE_LIBRARY}
  )

target_link_libraries(${PROJECT_NAME} ${LIBS})

set(CMAKE_CXX_FLAGS, "${CMAKE_CXX_FLAGS} -Wall -g")
set(CXX_STANDARD 20)




include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/609281088cfefc76f9d0ce82e1ff6c30cc3591e5.zip
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

enable_testing()

add_executable(
  hello_test
  test/hello_test.cpp
)
target_link_libraries(
  hello_test
  gtest_main
)

include(GoogleTest)
gtest_discover_tests(hello_test)
