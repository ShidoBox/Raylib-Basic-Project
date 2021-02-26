cmake_minimum_required(VERSION 3.17)
project(Basic_Project)

set(CMAKE_CXX_STANDARD 20)

include_directories(include)
link_directories(lib)

add_executable(${PROJECT_NAME} src/main.cpp)

if(MINGW)
target_link_libraries(${PROJECT_NAME} raylib winmm.lib)
endif()

if(LINUX)
target_link_libraries(${PROJECT_NAME} raylib pthread ${CMAKE_DL_LIBS})
endif()