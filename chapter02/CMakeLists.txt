# CMakeCook chapter02 切换生成器
# 1、将单个源码文件编译为可执行文件

# 设置CMake所需的最低版本
# FATAL_ERROR 如果使用的CMake版本低于该版本，则会发出致命错误
cmake_minimum_required(VERSION 3.5 FATAL_ERROR)

# 声明项目名称 编程语言C++
project(chapter01_01 LANGUAGES CXX)

# 生成可执行文件
# add_executable( 可执行文件名  源文件)
add_executable(hello_cmake recipe-01.cpp)