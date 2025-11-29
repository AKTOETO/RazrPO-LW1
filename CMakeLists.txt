cmake_minimum_required(VERSION 3.10)
project(sum)

# подключение библиотеки
add_subdirectory(lib/pqxx)

# Создание исполняемого файла
add_executable(${PROJECT_NAME} main.cpp file.cpp)

# подключение библиотеки к файлу
target_link_libraries(${PROJECT_NAME} pqxx)
target_include_directories(${PROJECT_NAME} PUBLIC lib/pqxx/include)

# Активация CTest
enable_testing() 

# Добавление исполняемого файла для теста
add_executable(test_sum tests/test_sum.cpp ../file.cpp)

# Регистрация теста, который будет запускаться командой ctest
add_test(NAME TestMySum COMMAND test_sum)