# project_euler
#

cmake_minimum_required(VERSION 2.6)

if("${CMAKE_CXX_COMPILER_ID}" STREQUAL "Clang" OR CMAKE_COMPILER_IS_GNUCXX)
  include(CheckCXXCompilerFlag)
  check_cxx_compiler_flag(--std=c++1y SUPPORTS_STD_CXX1Y)
  check_cxx_compiler_flag(--std=c++11 SUPPORTS_STD_CXX11)
  check_cxx_compiler_flag(--std=c++0x SUPPORTS_STD_CXX01)
  if(SUPPORTS_STD_CXX1Y)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} --std=c++1y")
  #elseif(SUPPORTS_STD_CXX11)
  #  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} --std=c++11")
  #elseif(SUPPORTS_STD_CXX01)
  #  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} --std=c++0x")
  else()
    message(ERROR "Compiler does not support --std=c++11 or --std=c++0x.")
  endif()
endif()

# naive solutions to the problems
add_executable(naive_problem1 naive_problem1.c++)

# smart solutions to the problems
add_executable(smart_problem1 smart_problem1.c++)

# optimal solutions to the problems - minimal runtime
add_executable(optimal_problem1 optimal_problem1.c++)

# ultimate solutions with best usability and performance
add_executable(ultimate_problem1 ultimate_problem1.c++)
