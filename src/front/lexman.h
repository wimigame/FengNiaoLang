#pragma once

#include <filesystem>
#include <unordered_map>

#include "lexer.h"

namespace fengniao::front{

class Lexman{
    public:
    Lexman();
    Lexman(const std::filesystem::path &file) {
    
    }
    //根据文件名加载源码文件
    bool LoadSource(const std::filesystem::path &file);
    //设置Lexer
    // LexerPtr SetLexer(const LexerPtr &lexer);
    private:
    //一堆已加载的Lexer
    // std::unordered_map<std::string, LexerPtr> _lexers;
    //当前的Lexer解析器
    LexerPtr _lexer;
};

}