cmake_minimum_required(VERSION 3.20)

project(lithium_thirdparty LANGUAGES CXX)

if(NOT CMAKE_BUILD_TYPE)
  set(CMAKE_BUILD_TYPE Release)
endif()

if(MSVC)
  add_compile_options(/W4 /WX)
else()
  add_compile_options(-Wall -Wextra -pedantic -Werror)
endif()

add_subdirectory(oatpp)
add_subdirectory(oatpp-swagger)
add_subdirectory(oatpp-websocket)
add_subdirectory(oatpp-openssl)
add_subdirectory(oatpp-zlib)
add_subdirectory(backward)
