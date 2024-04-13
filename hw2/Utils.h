#include "Constant.h"
// 删除字符串前后的空格
void myTrim(std::string& str) {
    size_t start = str.find_first_not_of(" \t\n\r");
    if (start == std::string::npos)
        return ;
    size_t end = str.find_last_not_of(" \t\n\r");
    str = str.substr(start, end - start + 1);
    return;
}

// 将 形如"/* xxx xxxx        */ xxxxxx" \
格式化为 pair{xxx xxxx, xxxxxx}
std::pair<std::string,std::string> formatToKeyValue(const std::string text){

}