cmake_minimum_required(VERSION 4.1)
project(PracticaExamen)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(PracticaExamen
        Figura.cpp
        Figura.h
        main.cpp
        Circulo.cpp
        Circulo.h)
