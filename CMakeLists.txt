# CMakeLists.txt for Lithium-Thirdparty
# This project is licensed under the terms of the GPL3 license.
#
# Project Name: Lithium-Thirdparty
# Description: All of the built-in thirdparty libraries
# Author: Max Qian
# License: GPL3

cmake_minimum_required(VERSION 3.20)
project(lithium_thirdparty LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

LIST(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/cmake_modules/")
LIST(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/../cmake_modules/")

if(NOT CMAKE_BUILD_TYPE)
  set(CMAKE_BUILD_TYPE Release)
endif()

add_subdirectory(oatpp)
add_subdirectory(oatpp-swagger)
add_subdirectory(oatpp-websocket)
add_subdirectory(oatpp-sqlite)
add_subdirectory(oatpp-openssl)
add_subdirectory(oatpp-zlib)
add_subdirectory(backward)
add_subdirectory(pocketpy)
add_subdirectory(libzippp)
add_subdirectory(tinyxml2)
add_subdirectory(cpp_httplib)
add_subdirectory(ccfits)