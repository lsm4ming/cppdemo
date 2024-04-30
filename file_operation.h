//
// Created by yj_lsm on 2024/4/29.
//

#ifndef HELLO_FILE_OPERATION_H
#define HELLO_FILE_OPERATION_H

#include <fcntl.h>
#include <sys/stat.h>
#include <dirent.h>
#include <cstring>
#include <unistd.h>
#include <fstream>
#include "common.h"

constexpr const char* PATH_SEPARATOR = "/";
constexpr const char* CURRENT_DIR = ".";
constexpr const char* PARENT_DIR = "..";
constexpr const size_t BUFF_SIZE = 4096;

typedef void (*WalkFunc)(const String&);

typedef void (*TextReadFunc)(const String&,const size_t&);

class FileOperation {
public:
    FileOperation() = default;

    static void walkPath(const String& path,WalkFunc wf);

    static void readTextFile(const String& path,TextReadFunc rf);
};


#endif //HELLO_FILE_OPERATION_H
