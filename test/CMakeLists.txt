cmake_minimum_required(VERSION 3.10)

include_directories("${PROJECT_SOURCE_DIR}/include")

add_executable(array_test array_test.c)
target_link_libraries(array_test c_struct)

enable_testing()

add_test(NAME array_test COMMAND array_test)
