cmake_minimum_required(VERSION 3.21)
project(AMV_ADD_2)

add_subdirectory(googletest)

enable_testing()
add_executable(AMV_ADD_2 main.cpp Graph.cpp Functions.cpp)
target_link_libraries(
        AMV_ADD_2
        gtest
        gtest_main
        pthread
)

add_executable(tests tests.cpp Graph.cpp Functions.cpp)
target_link_libraries(
        tests
        gtest
        gtest_main
        pthread
)

add_test(NAME unit
        COMMAND ${CMAKE_BINARY_DIR}/${CMAKE_INSTALL_BINDIR}/tests
        )