#include "VarContent.h"
#include "Utils.h"
VarContent::VarContent(std::istream &is)
    : ParaContent() // do nothing
{
    std::string line;
    while (getline(is, line))
    {
        // 删去头尾空格
        myTrim(line);
        if (line.size() == 0)
        {
            continue;
        }
        if (line[1] == '*') // property
        {
            auto p = formatToKeyValue(line);
            proporties[p.first] = p.second;
        }
        else if (line.substr(1, 5) == "begin") // begin
        {
            // sonParas.push_back();
        }
        else if (line.substr(1, 3) == "end") // end
        {
            return;
        }
    }
}
void VarContent::processLine(const std::string & line) {

}
bool VarContent::filter(const std::string & paraType) {
    return true;
}