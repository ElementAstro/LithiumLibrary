add_library(oatpp-sqlite
    mapping/type/Blob.cpp
    mapping/type/Blob.hpp
    mapping/Deserializer.cpp
    mapping/Deserializer.hpp
    mapping/ResultMapper.cpp
    mapping/ResultMapper.hpp
    mapping/Serializer.cpp
    mapping/Serializer.hpp
    ql_template/Parser.cpp
    ql_template/Parser.hpp
    ql_template/TemplateValueProvider.cpp
    ql_template/TemplateValueProvider.hpp
    Connection.cpp
    Connection.hpp
    ConnectionProvider.cpp
    ConnectionProvider.hpp
    Executor.cpp
    Executor.hpp
    QueryResult.cpp
    QueryResult.hpp
    Types.hpp
    orm.hpp
    Utils.cpp
    Utils.hpp
)

set_target_properties(oatpp-sqlite PROPERTIES
        CXX_STANDARD 17
        CXX_EXTENSIONS OFF
        CXX_STANDARD_REQUIRED ON
)

if(OATPP_MODULES_LOCATION STREQUAL OATPP_MODULES_LOCATION_EXTERNAL)
    add_dependencies(oatpp-sqlite ${LIB_OATPP_EXTERNAL})
endif()

target_link_libraries(oatpp-sqlite PUBLIC oatpp sqlite3)

target_include_directories(oatpp-sqlite
        PUBLIC $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>
)