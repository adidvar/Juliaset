cmake_minimum_required(VERSION 3.25.1)
project(Julia)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

file(COPY_FILE conanfile.txt ${CMAKE_BINARY_DIR}/conanfile.txt)
set(CMAKE_PREFIX_PATH "${CMAKE_BINARY_DIR};${CMAKE_PREFIX_PATH}")
set(CMAKE_MODULE_PATH "${CMAKE_BINARY_DIR};${CMAKE_MODULE_PATH}")

find_package(glfw3 REQUIRED)
find_package(glad REQUIRED)
find_package(glm REQUIRED)

add_executable(Julia src/main.cpp src/shader.h src/shader.cpp)
target_link_libraries(Julia opengl::opengl glfw3 glad::glad glm::glm)
