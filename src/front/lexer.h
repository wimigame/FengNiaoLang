#pragma once

#include <fstream>
#include <string>
#include "token.h"

namespace fengniao::front{

class Lexer {
    public:
    //参数一：待解析文件 参数二：标记用于区分正在解析哪个文件
    Lexer(const std::string filename, const std::string flag);
    Token NextToken();
    void NextChar();
    private:
    std::ifstream fileStream;
};

    using LexerPtr = std::shared_ptr<Lexer>;

}