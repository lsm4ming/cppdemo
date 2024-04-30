//
// Created by yj_lsm on 2024/4/30.
//

#include "md5.h"

String Md5Tool::md5(const String &input) {
    CryptoPP::MD5 hash;
    std::string digest;

    CryptoPP::StringSource give_me_a_name(input, true, new CryptoPP::HashFilter(hash, new CryptoPP::HexEncoder(new CryptoPP::StringSink(digest))));
    return digest;
}
