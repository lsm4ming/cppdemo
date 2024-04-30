//
// Created by yj_lsm on 2024/4/29.
//

#ifndef HELLO_MY_STRING_H
#define HELLO_MY_STRING_H

#include <cstring>
#include "common.h"

class MyString {
public:
    MyString() = default;

    MyString(const char *str);

    MyString(const MyString &str);

    MyString(MyString &&str) noexcept;

    MyString &operator=(const MyString &str);

    MyString &operator=(MyString &&str) noexcept ;

    ~MyString();

    [[nodiscard]] const char *c_str() const;

    friend std::ostream &operator<<(std::ostream &os, const MyString &str);

    MyString& operator+(const char *str);

    MyString& operator+(const MyString &str);

    MyString& append(const char *str);

    MyString& append(const MyString &str);

    int length() const;

private:
    char *m_data;
    size_t m_length;
};


#endif //HELLO_MY_STRING_H
