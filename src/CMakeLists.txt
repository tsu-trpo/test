cmake_minimum_required(VERSION 2.8.8)
project(${BIN_NAME})

# статическая библиотека
add_library(${LIB_NAME} STATIC
    bin_search.cpp
)
set_target_properties(${LIB_NAME} PROPERTIES
    INTERFACE_INCLUDE_DIRECTORIES ${CMAKE_CURRENT_SOURCE_DIR}
    INCLUDE_DIRECTORIES ${CMAKE_CURRENT_SOURCE_DIR}
)

# исполняемый файл
add_executable(${PROJECT_NAME}
    main.cpp
)
target_link_libraries(${PROJECT_NAME}
    ${LIB_NAME}
)

