cmake_minimum_required(VERSION 3.18.0)
project(cpp-tutorial VERSION 0.1.0)


include(CTest)
enable_testing()

add_executable(cpp-tutorial main.cpp)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)

target_compile_options(cpp-tutorial PRIVATE $<$<COMPILE_LANGUAGE:CXX>:-fcoroutines> -fconstexpr-ops-limit=671088640)
target_compile_features(cpp-tutorial PRIVATE cxx_std_20)
