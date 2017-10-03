cmake_minimum_required(VERSION 2.8.8)
project(${TESTS_NAME})

# список тестов
add_executable(${PROJECT_NAME}
    bin_search.cpp
    example.cpp
    main.cpp
)

target_link_libraries(${PROJECT_NAME}
    ${LIB_NAME}
    gtest
)
add_test(
    NAME ${PROJECT_NAME}
    COMMAND ${PROJECT_NAME} 
    "--gtest_output=xml:${CMAKE_BINARY_DIR}/reports/"
)
add_custom_target(${PROJECT_NAME}_autorun
    ALL
    ctest --output-on-failure
    DEPENDS ${PROJECT_NAME}
    WORKING_DIRECTORY ${CMAKE_BINARY_DIR}
)

