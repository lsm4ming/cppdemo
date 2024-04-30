//
// Created by yj_lsm on 2024/4/29.
//

#include "file_operation.h"

void FileOperation::walkPath(const String &path, WalkFunc wf) {
    struct stat path_stat{};
    if (stat(path.c_str(), &path_stat) != 0) {
        // 处理无法获取文件信息的情况
        perror("stat fail");
        return;
    }
    if (S_ISDIR(path_stat.st_mode)) { // 如果是目录
        DIR *dir = opendir(path.c_str());
        if (dir != nullptr) {
            struct dirent *entry;
            while ((entry = readdir(dir)) != nullptr) {
                if (strcmp(entry->d_name, CURRENT_DIR) == 0 || strcmp(entry->d_name, PARENT_DIR) == 0) {
                    continue; // 跳过当前目录和上一级目录
                }
                String full_path = path + PATH_SEPARATOR + entry->d_name;
                if (entry->d_type == DT_DIR) { // 判断是否为目录
                    walkPath(full_path, wf);
                } else {
                    wf(full_path); // 传递完整路径
                }
            }
            closedir(dir);
        }
        return;
    } else {
        wf(path);
    }
}

void FileOperation::readFile(const String &path, const std::function<void(std::ifstream &)> &processFile) {
    std::ifstream file(path);
    if (!file.is_open()) {
        perror("open file fail");
        return;
    }
    processFile(file);
    file.close();
}

void FileOperation::readTextFile(const String &path, TextReadFunc rf) {
    readFile(path, [rf](std::ifstream &file) {
        std::ostringstream buff;
        char chunk[BUFF_SIZE]; // 每次读取的块大小
        size_t size = 0;
        while (file.read(chunk, sizeof(chunk))) {
            buff.write(chunk, file.gcount());
            size += file.gcount();
        }
        if (file.eof()) { // 处理最后一块
            buff.write(chunk, file.gcount());
            size += file.gcount();
        } else {
            perror("read file fail");
        }
        rf(buff.str(), size);
    });
}

void FileOperation::readByteFile(const String &path, ByteReadFunc rf) {
    readFile(path, [rf](std::ifstream &file) {
        CharList buffer(BUFF_SIZE);
        size_t size = 0;
        while (file.read(buffer.data(), BUFF_SIZE)) {
            std::cout.write(buffer.data(), BUFF_SIZE);
            size += BUFF_SIZE;
        }
        // 处理剩余的不足一个缓冲区大小的字节
        std::cout.write(buffer.data(), file.gcount());
        size += file.gcount();
        rf(buffer, size);
    });
}
