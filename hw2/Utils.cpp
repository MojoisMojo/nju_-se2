#include "Utils.h"
// 删除字符串前后的空格
void myTrim(std::string &str)
{
    size_t start = str.find_first_not_of(" \t\n\r");
    if (start == std::string::npos)
        return;
    size_t end = str.find_last_not_of(" \t\n\r");
    str = str.substr(start, end - start + 1);
    return;
}

/// @brief 查看token中是否存在需要的模式
/// @param tokens 被匹配的字符
/// @param pattens 模式
bool isMatch(const std::string &tokens, const std::vector<std::string> &pattens)
{
    std::stringstream tokenStream(tokens);
    std::string token;
    while (tokenStream >> token)
    {
        for (auto &str : pattens)
        {
            if (token == str)
            {
                return true;
            }
        }
    }
    return false;
}