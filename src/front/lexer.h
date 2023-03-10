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
    private:
    bool IsOperator(char c);
    void NextChar();
    void SkipSpace();
    bool IsEnd();
    Token SplitId();
    Token SplitString();
    Token SplitChar();
    Token SplitNum();
    Token SplitOperator();
    Token SplitEnd();

    private:
    std::ifstream fileStream;
    char currentChar;
};

    using LexerPtr = std::shared_ptr<Lexer>;

}