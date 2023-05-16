cmake_minimum_required(VERSION 3.10)

include_directories("${PROJECT_SOURCE_DIR}/include")
link_directories("${PROJECT_BINARY_DIR}/lab")

add_executable(dy_arr_test dy_arr_test.c)
target_link_libraries(dy_arr_test dy_arr)

enable_testing()

add_test(NAME dy_arr_test COMMAND dy_arr_test)
