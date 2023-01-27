#pragma once

namespace fengniao::front{

enum class Token{
    EOL = 0,
    End = 1,
    Id = 2,
    Num = 3,
    String = 4,
    Keyword = 5,
    Operator = 6
};

}