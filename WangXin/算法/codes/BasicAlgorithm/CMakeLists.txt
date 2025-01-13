cmake_minimum_required(VERSION 3.27)
project(aa)

set(CMAKE_CXX_STANDARD 14)
# 设置可执行文件的输出目录
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
# 设置调试符号文件的输出目录（可选，macOS 上会影响 .dSYM）
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_DEBUG ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_RELEASE ${CMAKE_BINARY_DIR}/bin)

add_executable(aa main.cpp)

add_executable(quicksort quicksort.cpp)
add_executable(bianry bianry.cpp)
add_executable(sqrt sqrt.cpp)
add_executable(highPresionAddiition highPresionAddiition.cpp)
add_executable(higtPresionSub higtPresionSub.cpp)
add_executable(highPresionMul highPresionMul.cpp)
add_executable(highPresionDiv highPresionDiv.cpp)