#include "lexer.h"

#include <iostream>

using namespace fengniao::front;

Lexer::Lexer(const std::string filename, const std::string flag):fileStream(std::string(filename)){
    //不是结尾就一直读取
    while(!fileStream.eof()){
        NextChar();
    }
    fileStream.close();
}

void Lexer::NextChar(){
    char tmp;
    fileStream.get(tmp);

    printf("%c \n",tmp);
}