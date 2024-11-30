# Minimum required version of CMake
cmake_minimum_required(VERSION 3.10)

# Project name and C++ standard
project(net_recon VERSION 1.0 LANGUAGES CXX)

# Set the C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Path to the ASIO header files (assume ASIO is in the 'include/' folder)
include_directories(${CMAKE_SOURCE_DIR}/include/asio-1.30.2/include)

# List of source files
set(SOURCES
    src/main.cpp
    src/TcpScan.cpp
    src/BaseScan.cpp
    src/WriteResults.cpp
)

# List of header files (optional, but good for IDEs)
set(HEADERS
    src/BaseScan.h
    src/TcpScan.h
    src/WriteResults.h
)

find_package(nlohmann_json 3.0.0 REQUIRED)


# Add the source files to be compiled
add_executable(net_recon ${SOURCES} ${HEADERS})

# Link the pthread library, required for ASIO multithreading
target_link_libraries(net_recon pthread nlohmann_json::nlohmann_json)

add_definitions(-DASIO_STANDALONE)

