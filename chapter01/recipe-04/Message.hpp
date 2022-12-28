#pragma once
#include <iosfwd>
#include <string>


/**
 * @brief 类包装了一个字符串，并提供重载过的 << 操作，
 * 并且包括两个源码文件，hpp 头文件 与 cpp 源文件。
 */
class Message
{
public:

    // dtoc
    Message(const std::string &m) : message_(m) {}

    // 重载 <<
    friend std::ostream &operator<<(std::ostream &os, Message &obj)
    {
        return obj.printObject(os);
    }

private:
    std::string message_;
    std::ostream &printObject(std::ostream &os);
};