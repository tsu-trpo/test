cmake_minimum_required(VERSION 2.8.8)
project(searcher)

if (MSVC)
        set(CMAKE_C_FLAGS_RELEASE   "${CMAKE_C_FLAGS_RELEASE} /MT")
        set(CMAKE_C_FLAGS_DEBUG     "${CMAKE_C_FLAGS_DEBUG} /MTd")
        set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} /MT")
        set(CMAKE_CXX_FLAGS_DEBUG   "${CMAKE_CXX_FLAGS_DEBUG} /MTd")
endif (MSVC)

# включаем тесты
add_subdirectory(libs/googletest)
enable_testing()

# включаем отладочную информацию: -g
# включаем C++ 11
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g -std=c++11")

# заводим констранты, которые будем использовать в поддиректориях
set(LIB_NAME "${PROJECT_NAME}_lib")
set(BIN_NAME "${PROJECT_NAME}")
set(TESTS_NAME "${PROJECT_NAME}_tests")

add_subdirectory(src)
add_subdirectory(tests)
