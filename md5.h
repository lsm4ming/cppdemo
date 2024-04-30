//
// Created by yj_lsm on 2024/4/30.
//

#ifndef HELLO_MD5_H
#define HELLO_MD5_H

#include <md5.h>
#include <hex.h>
#include "common.h"

class Md5Tool {
public:
    static String md5(const String &input);
};


#endif //HELLO_MD5_H
