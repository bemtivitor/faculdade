cmake_minimum_required(VERSION 3.10)

project(truco LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_executable(truco
    truco.cpp
    lib/carta.cpp
    lib/baralho.cpp
    lib/jogo.cpp
    lib/monte.cpp
)

target_include_directories(truco PRIVATE lib)

if(MSVC)
    target_compile_options(truco PRIVATE /W4)
else()
    target_compile_options(truco PRIVATE -Wall -Wextra)
endif()