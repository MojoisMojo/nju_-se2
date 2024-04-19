#include "StdPara.h"
#include "Utils.h"
StdPara::StdPara()
{
}

StdPara::StdPara(std::istream &is)
{
}

ProcessCode StdPara::processLine(const std::string &line)
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
        }
    }
    return ProcessCode::PROCESS_CONTINUE;
}

bool StdPara::filter(ParaType)
{
    return true;
}

StdPara::~StdPara()
{
    for (auto &para : paraSonParas)
    {
        delete para;
        para = nullptr;
    }
}