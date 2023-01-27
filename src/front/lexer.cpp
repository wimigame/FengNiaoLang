#include "lexer.h"

#include <iostream>

using namespace fengniao::front;

Lexer::Lexer(const std::string filename, const std::string flag):fileStream(std::string(filename)){
    //不是结尾就一直读取
    // for(int i=0;i<3;i++){
    //     NextToken();
    //     printf("%d",i);
    // }
}

void Lexer::NextChar(){
    fileStream.get(currentChar);
}

bool Lexer::IsEnd(){
    return fileStream.eof() || currentChar == '\n' || currentChar == '\r';
}

void Lexer::SkipSpace(){
    while(!IsEnd() && std::isspace(currentChar)){
        NextChar();
    }
}

//接下来要实现拆分词语和获得词法类型
Token Lexer::NextToken(){
    if(fileStream.eof()){
        return Token::End;
    }

    //跳过空格和换行
    SkipSpace();

    //判断 Id类型 isalpha:判断是否为字母
    if(std::isalpha(currentChar)){
        return SplitId();
    }

    //判断 Num类型

    //判断 字符串类型

    //判断 字符类型

    //判断 操作符类型

    //判断 结束
    NextChar();

    return Token::End;
}

Token Lexer::SplitId(){
    //这里要区分是关键词 还是 变量名
    std::string id;
    do{
        id += currentChar;
        NextChar();
    //isalnum 判断是否是字母或数字
    }while(!IsEnd() && (std::isalnum(currentChar)));

    printf("搜索到符号：%s \n",id.c_str());
    return Token::Id;
}