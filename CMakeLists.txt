cmake_minimum_required(VERSION 3.15)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

project(treeview_clone 
    VERSION 1.0 
    DESCRIPTION "Clone of the treeview app"
    LANGUAGES C)

add_library(trev_lib STATIC 
    src/string_utils.c
    src/ls_cpy.c
    src/main.c)
target_include_directories(trev_lib PUBLIC include)
target_compile_features(trev_lib PUBLIC c_std_11)

add_executable(trev src/main.c)
target_link_libraries(trev PUBLIC trev_lib)

