cmake_minimum_required(VERSION 3.20)

# Примечание: придумайте нормальное название проекту (как это указано в Google таблице)
project(untitled3 CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(${PROJECT_NAME} main.cpp)

# Здесь указываются пути до конкретных исходных файлов (через пробел).
# Указанные исходные файлы войдут в состав исполняемого файла.
target_sources(${PROJECT_NAME} PRIVATE src/cartesian_tree.cpp)

# Подключение заголовочных файлов.
# Для подключения собственных заголовочных в любом месте используйте путь <assignment/...>.
target_include_directories(${PROJECT_NAME} PUBLIC include)
