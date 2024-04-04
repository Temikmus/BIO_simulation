cmake_minimum_required(VERSION 3.27)
project(BIO)

set(CMAKE_CXX_STANDARD 17)
#set(CMAKE_EXE_LINKER_FLAGS "-static -static-libgcc")
#set(SFML_STATIC_LIBRARIES TRUE)


add_executable(BIO main.cpp
        Animal.h
        Animal.cpp
        World.h
        World.cpp
        Info.h
        Info.cpp
        Field.h
        Field.cpp
        Graph.cpp
        Graph.cpp
        Graph.h)


#set(SFML_DIR "C:\\Users\\artem\\CLionProjects\\lib\\sfml\\GCC 13.1.0 MinGW (SEH) - 64-bit\\SFML-2.6.1\\lib\\cmake\\SFML")
#
#target_link_libraries(BIO sfml-graphics)
#
#set(CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/cmake_modules")
#find_package(SFML 2.6 REQUIRED graphics network audio window system)

