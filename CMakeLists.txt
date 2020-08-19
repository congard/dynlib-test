cmake_minimum_required(VERSION 3.16)
project(dynlib_test)

set(CMAKE_CXX_STANDARD 14)

if (NOT WIN32)
    set(CompileOptions -fPIC)
    set(LinkLibraries dl)
else()
    set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS TRUE)
    set(BUILD_SHARED_LIBS TRUE)
    add_compile_definitions(executable WIN32)
endif()

add_executable(executable main.cpp)

add_library(tulz SHARED tulz/DynamicLibrary.cpp tulz/DynamicLibrary.h)
add_library(animal SHARED Animal.cpp Animal.h)
add_library(dog SHARED Dog.cpp Dog.h)
add_library(cat SHARED Cat.cpp Cat.h)

target_compile_options(animal PRIVATE ${CompileOptions})
target_compile_options(dog PRIVATE ${CompileOptions})
target_compile_options(cat PRIVATE ${CompileOptions})

target_link_libraries(dog animal)
target_link_libraries(cat animal)

target_link_libraries(executable animal tulz ${LinkLibraries})

add_dependencies(executable dog cat)
