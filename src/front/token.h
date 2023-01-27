#pragma once

namespace fengniao::front{

enum class Token{
    EOL = 0,
    End = 1,
    Id = 2,
    Num = 3,
    String = 4,
    Char = 5,
    Keyword = 6,
    Operator = 7,
    Other = 8
};

}