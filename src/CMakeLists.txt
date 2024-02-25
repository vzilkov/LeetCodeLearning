cmake_minimum_required(VERSION 3.20)

set(SRC main.c)
add_executable(sources_build ${SRC})

add_library(palindrome_lib SHARED "")
target_sources(palindrome_lib PUBLIC palindrome.c palindrome.h)

add_library(topupdown_lib SHARED "")
target_sources(topupdown_lib PUBLIC topupdown.c topupdown.h)

add_library(search_alg_lib SHARED "")
target_sources(search_alg_lib PUBLIC search_alg.c search_alg.h)

add_library(bin_tree_lib SHARED "")
target_sources(bin_tree_lib PUBLIC bin_tree.c bin_tree.h)
target_include_directories(bin_tree_lib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

add_library(stack_training_lib SHARED "")
target_sources(stack_training_lib PUBLIC stack_training.c stack_training.h)

add_library(strings_training_lib SHARED "")
target_sources(strings_training_lib PUBLIC strings.c strings.h)

add_library(sorts_training_lib SHARED "")
target_sources(sorts_training_lib PUBLIC sorts.c sorts.h)

add_library(array_training_lib SHARED "")
target_sources(array_training_lib PUBLIC array_training.c array_training.h)

add_library(hash_table_lib SHARED "")
target_sources(hash_table_lib PUBLIC hash_table.c hash_table.h)

add_library(lists_lib SHARED "")
target_sources(lists_lib PUBLIC lists.c lists.h)

add_library(queue_lib SHARED "")
target_sources(queue_lib PUBLIC queue.c queue.h)

target_link_libraries(sources_build PUBLIC  palindrome_lib topupdown_lib search_alg_lib bin_tree_lib stack_training_lib 
                                            strings_training_lib sorts_training_lib array_training_lib hash_table_lib lists_lib
                                            queue_lib)


# add_library(palindrome_lib SHARED)
# target_sources(palindrome_lib PUBLIC palindrome.c)
# set_target_properties(palindrome_lib PROPERTIES LINKER_LANGUAGE C)