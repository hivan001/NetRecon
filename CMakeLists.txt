# Minimum required version of CMake
cmake_minimum_required(VERSION 3.10)

# Project name and C++ standard
project(my_asio_app VERSION 1.0 LANGUAGES CXX)

# Set the C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Path to the ASIO header files (assume ASIO is in the 'include/' folder)
include_directories(${CMAKE_SOURCE_DIR}/include/asio-1.30.2/include)

# List of source files
set(SOURCES
    src/main.cpp
    # src/TcpScan.cpp
)

# List of header files (optional, but good for IDEs)
set(HEADERS
    src/BaseScan.h
    src/TcpScan.h
)


# Add the source files to be compiled
add_executable(my_asio_app ${SOURCES} ${HEADERS})

# Link the pthread library, required for ASIO multithreading
target_link_libraries(my_asio_app pthread)

add_definitions(-DASIO_STANDALONE)

