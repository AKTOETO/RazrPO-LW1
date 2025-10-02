cmake_minimum_required(VERSION 3.10)
project(sum)


add_subdirectory(lib/pqxx)

add_executable(${PROJECT_NAME} main.cpp file.cpp)

target_link_libraries(${PROJECT_NAME} pqxx)
target_include_directories(${PROJECT_NAME} PUBLIC lib/pqxx/include)
