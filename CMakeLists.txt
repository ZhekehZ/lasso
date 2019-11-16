cmake_minimum_required(VERSION 3.15)
project(LASSO)

set(CMAKE_CXX_STANDARD 17)

add_executable(
        lasso
        main.cpp
        src/csv_reader.cpp
        src/lasso.cpp
)