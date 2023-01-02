# 1.5 向用户显示选项
# 在 CMakeLists.txt 中使用 option() 命令，
# 以选项的形式显示逻辑 开关，用于外部设置，从而切换构建系统的生成行为。
# option(<option_variable> "help string" [initial value])

# 1、
cmake_minimum_required(VERSION 3.5 FATAL_ERROR)
project(recipe-04 LANGUAGES CXX)

# 2、
# 用一个选项替换上一个示例的 命令。该选项将修 改 USE_LIBRARY 的值，并设置其默认值为   :
# set(USE_LIBRARY OFF)
option(USE_LIBRARY "Compile sources into a library" OFF)
# 输出信息
message(STATUS "[USE_LIBRARY] Compile sources into a library? ${USE_LIBRARY}")

# CMake提供   命令用来定义依赖于其他选项的选项 模块
include(CMakeDependentOption)
# second option depends on the value of the first
cmake_dependent_option(
    MAKE_STATIC_LIBRARY "Compile sources into a static library" OFF
    "USE_LIBRARY" ON
    )
# third option depends on the value of the first
cmake_dependent_option(
    MAKE_SHARED_LIBRARY "Compile sources into a shared library" ON
    "USE_LIBRARY" ON
    )

# 3、
#  CMake中定义 BUILD_SHARED_LIBS 全局变量，并设置为OFF。调用 add_libraries 
#  并省略第二个参数，将构建一个静态库:
# set(BUILD_SHARED_LIBS OFF)
# 设置为 ON 逻辑值为true 表明 add_libraries 生成动态库
set(BUILD_SHARED_LIBS ON)

# 4、然后，引入一个变量 _sources ，包括 Message.hpp 和 Message.cpp :
list(APPEND _sources Message.hpp Message.cpp)

# 5、然后，引入一个基于 USE_LIBRARY 值的 if-else 语句。如果逻辑为真， 
# 则 Message.hpp 和 Message.cpp 将打包成一个库:
if(USE_LIBRARY)
    # 使用库去链接
    # add_library will create a static library
    # since BUILD_SHARED_LIBS is OFF
    add_library(message ${_sources})
    add_executable(hello-world main.cpp)
    target_link_libraries(hello-world message)
else()
    # 直接编译到一个文件
    add_executable(hello-world main.cpp ${_sources})
endif()

