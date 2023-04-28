# Configurazione minimale per CMake
cmake_minimum_required(VERSION 3.16)
project(C02046)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

add_executable(c02046 src/main.cpp src/fractionV2.cpp)
add_executable(exercise1-1 src/series1-1.cpp)
add_executable(exercise2-1 src/series2-1.cpp)
add_executable(exercise2-2 src/series2-2.cpp)
add_executable(exercise3-1 src/series3-1.cpp)
add_executable(composition src/composition.cpp)
add_executable(owership src/ownership.cpp)
add_executable(uniqueptr src/uniqueptr.cpp)
add_executable(sharedptr src/sharedptr.cpp)
add_executable(mysmartpointers src/mysmartpointers.cpp)
add_executable(exceptions src/exceptions.cpp)
add_executable(inheritance src/inheritance.cpp src/employee.cpp src/lecturer.cpp src/researcher.cpp)
add_executable(todolist src/TodoList.cpp src/TodoElement.cpp src/TodoContainer.cpp)


