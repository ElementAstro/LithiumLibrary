/***************************************************************************
 *
 * Project         _____    __   ____   _      _
 *                (  _  )  /__\ (_  _)_| |_  _| |_
 *                 )(_)(  /(__)\  )( (_   _)(_   _)
 *                (_____)(__)(__)(__)  |_|    |_|
 *
 *
 * Copyright 2018-present, Leonid Stryzhevskyi <lganzzzo@gmail.com>
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *
 ***************************************************************************/

#ifndef oatpp_openssl_configurer_TrustStore_hpp
#define oatpp_openssl_configurer_TrustStore_hpp

#include "ContextConfigurer.hpp"

#include "oatpp/Types.hpp"

namespace oatpp { namespace openssl { namespace configurer {

/**
 * Context configurer for a trust store for certificate validation. <br>
 * Enables certificate validation and host name verification in the client.
 * @extends &id:oatpp::openssl::configurer::ContextConfigurer;.
 */
class TrustStore : public ContextConfigurer {
private:
  oatpp::String m_cafile;
  oatpp::String m_cadir;
public:

  /**
   * Constructor.
   * @param file - Name of file with trusted certificates in PEM format
   * @param dir - Name of directory containing trusted certificates, see `c_rehash`
   */
  TrustStore(const oatpp::String& file, const oatpp::String& dir);

  void configure(SSL_CTX* ctx) override;

};

}}}

#endif // oatpp_openssl_configurer_TrustStore_hpp
