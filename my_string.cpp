//
// Created by yj_lsm on 2024/4/29.
//

#include "my_string.h"

MyString::MyString(const char *str) {
    this->m_length = std::strlen(str);
    this->m_data = new char[this->m_length + 1];
    std::strcpy(this->m_data, str);
}

MyString::MyString(const MyString &str) {
    this->m_length = str.m_length;
    this->m_data = new char[this->m_length + 1];
    std::strcpy(this->m_data, str.m_data);
}

MyString::MyString(MyString &&str) noexcept {
    this->m_length = str.m_length;
    this->m_data = str.m_data;
    str.m_data = nullptr;
    str.m_length = 0;
}

MyString::~MyString() {
    delete[] this->m_data;
    this->m_data = nullptr;
    this->m_length = 0;
}

MyString &MyString::operator=(const MyString &str) {
    if (this == &str) {
        return *this;
    }
    delete[] this->m_data;
    this->m_length = str.m_length;
    this->m_data = new char[this->m_length + 1];
    std::strcpy(this->m_data, str.m_data);
    return *this;
}

MyString &MyString::operator=(MyString &&str) noexcept {
    if (this == &str) {
        return *this;
    }
    delete[] this->m_data;
    this->m_length = str.m_length;
    this->m_data = str.m_data;
    str.m_data = nullptr;
    str.m_length = 0;
    return *this;
}

const char *MyString::c_str() const {
    return this->m_data;
}

std::ostream &operator<<(std::ostream &os, const MyString &str) {
    os << str.m_data;
    return os;
}

MyString &MyString::append(const char *str) {
    size_t len = std::strlen(str);
    if (len == 0) {
        return *this;
    }
    char *new_data = new char[this->m_length + len + 1];
    std::strcpy(new_data, this->m_data);
    std::strcpy(new_data + this->m_length, str);
    delete[] this->m_data;
    this->m_data = new_data;
    this->m_length += len;
    return *this;
}

MyString &MyString::append(const MyString &str) {
    return this->append(str.c_str());
}

MyString &MyString::operator+(const char *str) {
    return this->append(str);
}

MyString &MyString::operator+(const MyString &str) {
    return this->append(str.c_str());
}

int MyString::length() const {
    return this->m_length;
}
