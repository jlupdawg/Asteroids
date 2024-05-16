cmake_minimum_required(VERSION 3.10)

# Set the project name
project(ArrowCanvas)

# Specify the C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Specify the path to SFML
# Set the SFML_DIR to the path where SFML is installed
set(SFML_DIR "./lib/SFML-2.6.1/lib/cmake/SFML")

# Find the SFML package
find_package(SFML 2.6.1 COMPONENTS graphics window system REQUIRED)

# Add the executable
add_executable(ArrowCanvas src/main.cpp)

# Link SFML libraries
target_link_libraries(ArrowCanvas sfml-graphics sfml-window sfml-system)
