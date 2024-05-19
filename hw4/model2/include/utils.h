#ifndef UTILS_H
#define UTILS_H
#include <string>
#include <vector>
// 默认为 空格
std::vector<std::string> splitString(const std::string &str, char splitChar = ' ')
{
    std::vector<std::string> tokens;
    std::string token;
    size_t start = 0;
    size_t end = str.find(splitChar);

    while (end != std::string::npos)
    {
        token = str.substr(start, end - start);
        tokens.push_back(token);
        start = end + 1;
        end = str.find(splitChar, start);
    }

    token = str.substr(start, end);
    tokens.push_back(token);

    return tokens;
}
#endif