cmake_minimum_required(VERSION 3.20)

project(lithium_thirdparty LANGUAGES CXX)

add_subdirectory(oatpp)
add_subdirectory(oatpp-swagger)
add_subdirectory(oatpp-websocket)
add_subdirectory(oatpp-openssl)
add_subdirectory(oatpp-zlib)
add_subdirectory(backward)
add_subdirectory(libhv)
add_subdirectory(pocketpy)