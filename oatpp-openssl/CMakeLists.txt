add_library(oatpp-openssl
        oatpp-openssl/Config.cpp
        oatpp-openssl/Config.hpp
        oatpp-openssl/Connection.cpp
        oatpp-openssl/Connection.hpp
        oatpp-openssl/ErrorStack.cpp
        oatpp-openssl/ErrorStack.hpp
        oatpp-openssl/client/ConnectionProvider.cpp
        oatpp-openssl/client/ConnectionProvider.hpp
        oatpp-openssl/server/ConnectionProvider.cpp
        oatpp-openssl/server/ConnectionProvider.hpp
        oatpp-openssl/configurer/CaCertificateBundleBuffer.cpp
        oatpp-openssl/configurer/CaCertificateBundleBuffer.hpp
        oatpp-openssl/configurer/CertificateChainBuffer.cpp
        oatpp-openssl/configurer/CertificateChainBuffer.hpp
        oatpp-openssl/configurer/CertificateChainFile.cpp
        oatpp-openssl/configurer/CertificateChainFile.hpp
        oatpp-openssl/configurer/CertificateBuffer.cpp
        oatpp-openssl/configurer/CertificateBuffer.hpp
        oatpp-openssl/configurer/CertificateFile.cpp
        oatpp-openssl/configurer/CertificateFile.hpp
        oatpp-openssl/configurer/ContextConfigurer.hpp
        oatpp-openssl/configurer/Groups.cpp
        oatpp-openssl/configurer/Groups.hpp
        oatpp-openssl/configurer/PeerCertificateVerification.cpp
        oatpp-openssl/configurer/PeerCertificateVerification.hpp
        oatpp-openssl/configurer/PrivateKeyBuffer.cpp
        oatpp-openssl/configurer/PrivateKeyBuffer.hpp
        oatpp-openssl/configurer/PrivateKeyFile.cpp
        oatpp-openssl/configurer/PrivateKeyFile.hpp
        oatpp-openssl/configurer/TemporaryDhParamsFile.cpp
        oatpp-openssl/configurer/TemporaryDhParamsFile.hpp
        oatpp-openssl/configurer/TrustStore.cpp
        oatpp-openssl/configurer/TrustStore.hpp
)

set_target_properties(${OATPP_THIS_MODULE_NAME} PROPERTIES
CXX_STANDARD 11
CXX_EXTENSIONS OFF
CXX_STANDARD_REQUIRED ON
)

if(OATPP_MODULES_LOCATION STREQUAL OATPP_MODULES_LOCATION_EXTERNAL)
add_dependencies(${OATPP_THIS_MODULE_NAME} ${LIB_OATPP_EXTERNAL})
endif()

target_link_libraries(oatpp-openssl PUBLIC oatpp)

target_include_directories(oatpp-openssl
        PUBLIC $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>
)

find_package(OpenSSL REQUIRED)

target_link_libraries(oatpp-openssl
        PUBLIC OpenSSL::SSL
        PUBLIC OpenSSL::Crypto
)
