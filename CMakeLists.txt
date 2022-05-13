cmake_minimum_required(VERSION 3.20)
project("raytracer-deluxe" VERSION 0.0.1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_subdirectory(lib/Catch2-2.13.8)
add_subdirectory(lib/range-v3-0.11.0)

set(SOURCES
    src/main.cc
    src/ray.h
    src/vec3.h
    src/sphere.h
)

include(cmake/CompilerFlags.cmake)

add_executable(${PROJECT_NAME} ${SOURCES})

add_compiler_diagnostics(${PROJECT_NAME})

target_include_directories(${PROJECT_NAME} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/src)

target_link_libraries(${PROJECT_NAME} PRIVATE )
