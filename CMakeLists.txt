cmake_minimum_required(VERSION 3.14)
project(graph)

# Configuration
set(BIN_NAME graph)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

add_compile_options(-std=c++17)

# Sources

add_subdirectory(src)

# Third-party

find_package(Boost 1.69 COMPONENTS graph)
if(Boost_FOUND)
    include_directories(${Boost_INCLUDE_DIRS})
    target_link_libraries(${BIN_NAME} ${Boost_LIBRARIES})
endif()
