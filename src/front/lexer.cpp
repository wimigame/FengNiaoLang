#include "lexer.h"

#include <iostream>

using namespace fengniao::front;

const char *KeyWords[] = {
    "fn","let","var",
    "as",
    "num","string","char",
    "bool","true","false",
    "import","pub",
    "if","elif","else",
    "while",
    "for","in",
    "break","continue","return"
};

Lexer::Lexer(const std::string filename, const std::string flag):fileStream(std::string(filename)){
    //不是结尾就一直读取
    // for(int i=0;i<50;i++){
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

//接下来要实现拆分词语和获得词法类型 只要持续调用NextToken即可实现完整解析
Token Lexer::NextToken(){
    if(fileStream.eof()){
        return Token::End;
    }

    //跳过空格和换行
    SkipSpace();

    //判断 Id类型 isalpha:判断是否为字母
    if(std::isalpha(currentChar)){
        printf(" Id ");
        return SplitId();
    }

    // //判断 Num类型
    if(std::isdigit(currentChar)){
        printf(" Num ");
        return SplitNum();
    }

    // //判断 字符串类型
    if(currentChar == '"'){
        printf(" String ");
        return SplitString();
    }

    // //判断 字符类型
    if(currentChar == '\''){
        printf(" Char \n");
        return SplitChar();
    }

    // //判断 操作符类型
    if(IsOperator(currentChar)){
        printf(" Operator ");
        return SplitOperator();
    }

    // //判断 结束
    if(IsEnd()){
        printf(" End \n");
        return SplitEnd();
    }

    if(currentChar == ';'){
        NextChar();
        return Token::End;
    }

    NextChar();
    printf(" Other \n");

    return Token::Other;
}

template <typename T, std::size_t N>
int IsKeyword(const char *str, T (&keyword_array)[N]){
    for (std::size_t i = 0; i < N; ++i) {
        if (!std::strcmp(str, keyword_array[i])) return i;
    }
  return -1;
}

bool Lexer::IsOperator(char c) {
  const char op_chars[] = "`~!@#$%^&*-=+\\|:<.>/?";
  int d = 0;
  for (const auto &i : op_chars) {
    d+=1;
    if (i == c && c != '\0'){
        return true;
    }
  }
  return false;
}

Token Lexer::SplitId(){
    //这里要区分是关键词 还是 变量名
    std::string id;
    do{
        id += currentChar;
        NextChar();
    //isalnum 判断是否是字母或数字
    }while(!IsEnd() && (std::isalnum(currentChar)));

    int index = IsKeyword(id.c_str(),KeyWords);

    if(index < 0){
        printf("%s \n",id.c_str());
        return Token::Id;
    }else{
        printf("%s \n",id.c_str());
        return Token::Keyword;
    }
}

Token Lexer::SplitNum(){
    std::string num;

    while (!IsEnd() && (std::isxdigit(currentChar) || currentChar == '.')) {
        num += currentChar;
        NextChar();
    }

    printf("%s \n",num.c_str());

    return Token::Num;
}

Token Lexer::SplitString(){
    std::string str;
    NextChar();
    while(currentChar != '"'){
        str += currentChar;
        NextChar();
    }

    printf("%s \n",str.c_str());
    NextChar();
    return Token::String;
}

Token Lexer::SplitChar(){
    return Token::Char;
}

Token Lexer::SplitOperator(){
    std::string op;
    op += currentChar;
    NextChar();

    //读取剩余字符 例如：+=
    while (!IsEnd() && IsOperator(currentChar)) {
        op += currentChar;
        NextChar();
    }

    printf("%s \n",op.c_str());

    return Token::Operator;
}

Token Lexer::SplitEnd(){
    do{
        NextChar();
    }while(IsEnd() && !fileStream.eof());
    return Token::End;
}