cmake_minimum_required(VERSION 3.10)
project(plugin-example)

add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/sdk)

add_library(plugin-example SHARED plugin-example.cpp)
target_link_libraries(plugin-example PRIVATE lua::lib)

target_include_directories(plugin-example PRIVATE
 ${CMAKE_CURRENT_SOURCE_DIR}
 ${CMAKE_CURRENT_SOURCE_DIR}/sdk
)