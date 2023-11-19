project(GoogleLearning)
cmake_minimum_required(VERSION 3.20)

add_subdirectory(include)
add_subdirectory(src)

enable_testing()
add_subdirectory(tests)