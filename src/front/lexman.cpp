#include "lexman.h"

using namespace fengniao::front;

Lexman::Lexman(){

}

bool Lexman::LoadSource(const std::filesystem::path &file){
    //文件不存在
    if(!std::filesystem::exists(file)){
        return false;
    }

    auto full_path = std::filesystem::canonical(std::filesystem::absolute(file));
    auto file_str = full_path.string();

    _lexer = std::make_shared<Lexer>(file_str,file.string());

    return true;
}

// LexerPtr SetLexer(const LexerPtr &lexer){
//     auto last = _lexer;
//     _lexer = lexer;
//     return last;
// }