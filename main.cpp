#include <iostream>
#include <sys/epoll.h>
#include "file_operation.h"
#include "md5.h"

int main() {
//    FileOperation::walkPath("/home/lsm" , [](const String& path)->void{
//        std::cout << path << std::endl;
//    });

    FileOperation::readTextFile("/home/lsm/kafka/docker-compose.yaml",
                                [](const String &text, const size_t &len) -> void {
                                    std::cout << text << std::endl;
                                    std::cout << Md5Tool::md5(text) << std::endl;
                                });
    return 0;
}
