# CMakeLists.txt for Lithium-Thirdparty
# This project is licensed under the terms of the GPL3 license.
#
# Project Name: Lithium-Thirdparty
# Description: All of the built-in thirdparty libraries
# Author: Max Qian
# License: GPL3

cmake_minimum_required(VERSION 3.20)
project(lithium.thirdparty LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

LIST(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/cmake_modules/")
LIST(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/../cmake_modules/")

function(add_subdirectories_recursively start_dir)
  file(GLOB entries "${start_dir}/*")
  foreach(entry ${entries})
    if(IS_DIRECTORY ${entry} AND EXISTS "${entry}/CMakeLists.txt")
      message(STATUS "Adding thirdparty library subdirectory: ${entry}")
      add_subdirectory(${entry})
    endif()
  endforeach()
endfunction()
add_subdirectories_recursively(${CMAKE_CURRENT_SOURCE_DIR})
