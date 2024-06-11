
add_library(oatpp-websocket
        oatpp-websocket/AsyncConnectionHandler.cpp
        oatpp-websocket/AsyncConnectionHandler.hpp
        oatpp-websocket/AsyncWebSocket.cpp
        oatpp-websocket/AsyncWebSocket.hpp
        oatpp-websocket/Config.hpp
        oatpp-websocket/ConnectionHandler.cpp
        oatpp-websocket/ConnectionHandler.hpp
        oatpp-websocket/Connector.cpp
        oatpp-websocket/Connector.hpp
        oatpp-websocket/Frame.cpp
        oatpp-websocket/Frame.hpp
        oatpp-websocket/Handshaker.cpp
        oatpp-websocket/Handshaker.hpp
        oatpp-websocket/SHA1.cpp
        oatpp-websocket/SHA1.hpp
        oatpp-websocket/Utils.cpp
        oatpp-websocket/Utils.hpp
        oatpp-websocket/WebSocket.cpp
        oatpp-websocket/WebSocket.hpp
)

set_target_properties(oatpp-websocket PROPERTIES
        CXX_STANDARD 11
        CXX_EXTENSIONS OFF
        CXX_STANDARD_REQUIRED ON
)

if(OATPP_MODULES_LOCATION STREQUAL OATPP_MODULES_LOCATION_EXTERNAL)
    add_dependencies(oatpp-websocket ${LIB_OATPP_EXTERNAL})
endif()

target_link_libraries(oatpp-websocket PUBLIC oatpp)

target_include_directories(oatpp-websocket
        PUBLIC $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>
)
