project(GoogleLearning)
cmake_minimum_required(VERSION 3.20)

add_subdirectory(include)
add_subdirectory(src)
add_subdirectory(tests)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

enable_testing()
