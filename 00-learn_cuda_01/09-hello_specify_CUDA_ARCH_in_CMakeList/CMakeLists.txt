cmake_minimum_required(VERSION 3.10)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_BUILD_TYPE Release)
set(CMAKE_CUDA_ARCHITECTURES 52;70;75;86)

project(hellocuda LANGUAGES CXX CUDA)

add_executable(main main.cu)