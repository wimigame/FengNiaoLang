//基于教程： https://llvm.org/docs/tutorial/MyFirstLanguageFrontend/LangImpl02.html

#include <iostream>

#include "front/lexman.h"

using namespace fengniao::front;

//人生中第一次用C++做项目，写个main函数和打印输出都感觉是如此的不同。
int main(int agrc,char * argv[]){
    printf("%s","你好世界");

    //获取待编译的文件名
    char* filename = argv[1];
    printf("接收到待编译文件 %s \n",filename);

    Lexman lexman;
    //加载文件
    lexman.LoadSource(filename);

    return 0;
}