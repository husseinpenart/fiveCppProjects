cmake_minimum_required(VERSION 3.10)
project(fiveProjects)
# crud set cmake items set(SOURCE_FILE main.cpp Student.cpp)
#todo list set(SOURCE_FILE TaskSource.cpp  Task.cpp)
# book management 
set(SOURCE_FILE BookManagement.cpp  Book.cpp)
add_executable(hello ${SOURCE_FILE})

