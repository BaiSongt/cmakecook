# set minimum cmake version
cmake_minimum_required(VERSION 3.5 FATAL_ERROR)

# project name and language
project(recipe-09 LANGUAGES CXX)

# 要求在Windows上导出所有库符号:
set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS ON)

add_library(animals
  SHARED
    Animal.cpp
    Animal.hpp
    Cat.cpp
    Cat.hpp
    Dog.cpp
    Dog.hpp
    Factory.hpp
  )
#  为目标设置
# 了CXX_STANDARD、CXX_EXTENSIONS CXX_STANDARD_REQUIRED属性。还设置了
# position_independent end_code 属性，以避免在使用一些编译器构 建DSO时出现问题:
set_target_properties(animals
  PROPERTIES
    CXX_STANDARD 14
    CXX_EXTENSIONS OFF
    CXX_STANDARD_REQUIRED ON
    POSITION_INDEPENDENT_CODE 1
  )

# CXX_STANDARD 会设置我们想要的标准。 
# CXX_EXTENSIONS 告诉CMake，只启用 ISO C++ 标准的编译器标志，而不使用特定编译器的扩展。 
# CXX_STANDARD_REQUIRED 指定所选标准的版本。如果这个版本不可用，
#     CMake将停止配置并出现错误。当这个属性被设置为 OFF 时，
#     CMake 将寻找下一个标准的最新版本，直到一个合适的标志。
#     这意味着，首先查找 C++ 14，然后是 C++ 11 ，然后是 C++98 。
#     (译者注:目前会从 C++20 或 C++17 开始查找)

# 为"动物农场"的可执行文件添加一个新目标，并设置它的属性:
add_executable(animal-farm animal-farm.cpp)

set_target_properties(animal-farm
  PROPERTIES
    CXX_STANDARD 14
    CXX_EXTENSIONS OFF
    CXX_STANDARD_REQUIRED ON
  )

target_link_libraries(animal-farm animals)
