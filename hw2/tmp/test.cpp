// #include <iostream>
// #include <string>
// #include <utility>
// #include "Utils.h"
// typedef std::pair<std::string, std::string> Property;

// Property formatToKeyValue(const std::string &text)
// {
//     Property result;
//     // 查找注释的起始位置
//     size_t beginPos = text.find("/*");
//     if (beginPos != std::string::npos)
//     {
//         size_t endPos = text.find("*/", beginPos + 2);
//         if (endPos != std::string::npos)
//         {
//             std::string comment = text.substr(beginPos + 2, endPos - beginPos - 2);
//             std::string content = text.substr(endPos + 2);
//             myTrim(comment);
//             myTrim(content);
//             result = {comment, content};
//         }
//         else
//         {
//             result = std::make_pair("", "");
//         }
//     }
//     else
//     {
//         std::string value = text;
//         myTrim(value);
//         int i = 0, length = value.size();
//         while (length > i && value[i] == '\"')
//         {
//             ++i;
//         }
//         value.erase(0, i);
//         i = value.size() - 1;
//         length = value.size();
//         while (0 <= i && value[i] == '\"')
//         {
//             --i;
//         }
//         value.erase(i + 1, length - i - 1);

//         result = std::make_pair("", value);
//     }

//     return result;
// }

// int main()
// {
//     std::string text1 = "/* xxx xxxx        */ xxxxxx";
//     std::string text2 = "xxxxxx";
//     Property prop1 = formatToKeyValue(text1);
//     Property prop2 = formatToKeyValue(text2);
//     std::cout << "Property 1: {" << prop1.first << "," << prop1.second << "}" << std::endl;
//     std::cout << "Property 2: {" << prop2.first << "," << prop2.second << "}" << std::endl;

//     return 0;
// }
