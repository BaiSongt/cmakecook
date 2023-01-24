# 1.7 切换构建类型
cmake_minimum_required(VERSION 3.5 FATAL_ERROR)

project(recipe-07 LANGUAGES C CXX)

# 设置一个默认的构建类型(本例中是Release)，并打印一条消息。
# 要注意的是，该变量被设置为缓存变量，可以通过缓存进行编辑:
if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Release CACHE STRING "Build type" FORCE
)
endif()
message(STATUS "Build type: ${CMAKE_BUILD_TYPE}")

# 打印出CMake设置的相应编译标志:
message(STATUS "C flags, Debug configuration: ${CMAKE_C_FLAGS_DEBUG}")
message(STATUS "C flags, Release configuration: ${CMAKE_C_FLAGS_RELEASE}")
message(STATUS "C flags, Release configuration with Debug info: ${CMAKE_C_FLAGS_RELWITHDEBINFO}")
message(STATUS "C flags, minimal Release configuration: ${CMAKE_C_FLAGS_MINSIZEREL}")
message(STATUS "C++ flags, Debug configuration: ${CMAKE_CXX_FLAGS_DEBUG}")
message(STATUS "C++ flags, Release configuration: ${CMAKE_CXX_FLAGS_RELEASE}")
message(STATUS "C++ flags, Release configuration with Debug info: ${CMAKE_CXX_FLAGS_RELWITHDEBINFO}")
message(STATUS "C++ flags, minimal Release configuration: ${CMAKE_CXX_FLAGS_MINSIZEREL}")