
add_library(oatpp-swagger
        oatpp-swagger/AsyncController.hpp
        oatpp-swagger/Controller.hpp
        oatpp-swagger/ControllerPaths.hpp
        oatpp-swagger/Generator.cpp
        oatpp-swagger/Generator.hpp
        oatpp-swagger/Model.hpp
        oatpp-swagger/Resources.cpp
        oatpp-swagger/Resources.hpp
        oatpp-swagger/Types.cpp
        oatpp-swagger/Types.hpp
        oatpp-swagger/oas3/Model.hpp
)

set_target_properties(oatpp-swagger PROPERTIES
        CXX_STANDARD 11
        CXX_EXTENSIONS OFF
        CXX_STANDARD_REQUIRED ON
)

if(OATPP_MODULES_LOCATION STREQUAL OATPP_MODULES_LOCATION_EXTERNAL)
    add_dependencies(oatpp-swagger ${LIB_OATPP_EXTERNAL})
endif()

target_link_libraries(oatpp-swagger PUBLIC oatpp)

target_include_directories(oatpp-swagger
        PUBLIC $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>
)
