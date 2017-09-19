cmake_minimum_required(VERSION 2.8.8)
project(searcher)

# включаем отладочную информацию: -g
# включаем C++ 11
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g -std=c++11")

# заводим констранты, которые будем использовать в поддиректориях
set(LIB_NAME "${PROJECT_NAME}_lib")
set(BIN_NAME "${PROJECT_NAME}")

add_subdirectory(src)
