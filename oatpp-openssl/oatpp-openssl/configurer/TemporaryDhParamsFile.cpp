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

#include "TemporaryDhParamsFile.hpp"

namespace oatpp { namespace openssl { namespace configurer {

TemporaryDhParamsFile::TemporaryDhParamsFile(const oatpp::String &filename)
    : m_filename(filename)
{}

void TemporaryDhParamsFile::configure(SSL_CTX *ctx) {
    std::shared_ptr<BIO> bio(BIO_new_file(m_filename->c_str(), "r"), BIO_free);
    if (!bio) {
        throw std::runtime_error("[oatpp::openssl::configurer::TemporaryDhParamsFile::configure()]: Error. "
                                 "Call to 'BIO_new_file' failed.");
    }

    std::shared_ptr<EVP_PKEY> pkey(PEM_read_bio_PrivateKey(bio.get(), nullptr, nullptr, nullptr), EVP_PKEY_free);
    if (!pkey) {
        throw std::runtime_error("[oatpp::openssl::configurer::TemporaryDhParamsFile::configure()]: Error. "
                                 "Call to 'PEM_read_bio_PrivateKey' failed.");
    }

    if (SSL_CTX_set0_tmp_dh_pkey(ctx, pkey.get()) <= 0) {
        throw std::runtime_error("[oatpp::openssl::configurer::TemporaryDhParamsFile::configure()]: Error. "
                                 "Call to 'SSL_CTX_set0_tmp_dh_pkey' failed.");
    }
}

}}}

