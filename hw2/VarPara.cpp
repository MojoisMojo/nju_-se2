#include "VarPara.h"
#include "Utils.h"
#include "Constant.h"
VarPara::VarPara(std::istream &is)
    : StdPara() // do nothing
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
        if (processLine(line) != ProcessCode::PROCESS_CONTINUE)
        {
            return;
        }
    }
}
ProcessCode VarPara::processLine(const std::string &line)
{
    if (line.substr(1, 5) == "begin") // begin
    {
        std::string paraType = line.substr(6);
        // paraSonParas.push_back();
    }
    else if (line.substr(1, 3) == "end") // end
    {
        return ProcessCode::PROCESS_END;
    }
    else
    {

        auto p = formatToKeyValue(line);
        if (p.first.empty())
        {
            paraContents.push_back(p.second);
        }
        else
        {
            paraProporties[p.first] = p.second;
            if (isName(p.first))
            {
                varName = p.second;
            }
            else if (isIdentfier(p.first))
            {
                varIdentifier = p.second;
            }
        }
    }
    return ProcessCode::PROCESS_CONTINUE;
}
bool VarPara::filter(ParaType paraType)
{
    return true;
}

VarPara::~VarPara()
{
    // do nothing
}