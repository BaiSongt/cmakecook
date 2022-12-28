# 构建和链接静态库和动态库

cmake_minimum_required(VERSION 3.5)
project(Message LANGUAGES CXX)

# 1、创建目标--静态库  库的名称和源码文件名相同
add_library(message
  #STATIC  静态
  SHARED
    Message.hpp
    Message.cpp
  )

# 2、创建 hello-world 
add_executable(hello-world main.cpp)

# 3、将目标库链接到可执行目标:
target_link_libraries(hello-world message)