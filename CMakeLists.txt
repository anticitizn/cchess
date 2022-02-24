cmake_minimum_required(VERSION 3.16)
project(cchess)

file(GLOB SOURCES src/*.c)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}/build/")

add_executable(${PROJECT_NAME} ${SOURCES} main.c)

target_include_directories(${PROJECT_NAME} PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}")
target_link_libraries(${PROJECT_NAME} ${CMAKE_DL_LIBS})
