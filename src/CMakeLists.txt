cmake_minimum_required(VERSION 3.20)

set(SRC main.c)
add_executable(sources_build ${SRC})

add_library(palindrome_lib SHARED "")
target_sources(palindrome_lib PRIVATE palindrome.c palindrome.h)

add_library(topupdown_lib SHARED "")
target_sources(topupdown_lib PRIVATE topupdown.c topupdown.h)

add_library(search_alg_lib SHARED "")
target_sources(search_alg_lib PRIVATE search_alg.c search_alg.h)

add_library(bin_tree_lib SHARED "")
target_sources(bin_tree_lib PRIVATE bin_tree.c bin_tree.h)

add_library(stack_training_lib SHARED "")
target_sources(stack_training_lib PRIVATE stack_training.c stack_training.h)

add_library(strings_training_lib SHARED "")
target_sources(strings_training_lib PRIVATE strings.c strings.h)

target_link_libraries(sources_build PUBLIC palindrome_lib topupdown_lib search_alg_lib bin_tree_lib stack_training_lib strings_training_lib)


# add_library(palindrome_lib SHARED)
# target_sources(palindrome_lib PUBLIC palindrome.c)
# set_target_properties(palindrome_lib PROPERTIES LINKER_LANGUAGE C)