#include "StdPara.h"
#include "Utils.h"
#include "Constant.h"
StdPara::StdPara(std::istream &fin, ParaType pType, BasePara *pFather = nullptr)
    : BasePara(pType, pFather)
{
    std::string line;
    while (getline(fin, line))
    {
        // 删去头尾空格
        myTrim(line);
        if (line.size() == 0)
        {
            continue;
        }
        if (processLine(fin, line) != ProcessCode::PROCESS_CONTINUE)
        {
            return;
        }
    }
}

ProcessCode StdPara::processLine(std::istream &fin, const std::string &line)
{
    if (line.substr(1, 5) == "begin") // begin
    {
        std::stringstream sline(line.substr(6));
        std::string stype;
        sline >> stype;
        ParaType sonType = string2ParaType(stype);
        if (filter(sonType))
        {
            BasePara * sonPara = new StdPara(fin,sonType,this);
            mSonParas.push_back(sonPara);
        }
        throw("变量 格式错误");
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
            mParaContents.push_back(p.second);
        }
        else
        {
            mParaProporties[p.first] = p.second;
        }
    }
    return ProcessCode::PROCESS_CONTINUE;
}

bool StdPara::filter(ParaType)
{
    return true;
}
std::ostream &StdPara::print(std::ostream &os)
{
    os << "ParaType: " << PARA_TYPE_STRINGS[(int)mParaType] << "\n";
    for (auto &[key, value] : mParaProporties)
    {
        os << key << ": " << value << "\n";
    }
    for (auto &value : mParaContents)
    {
        os << value << "\n";
    }
    for (auto sonPara : mSonParas)
    {
        os << "\t" << (*sonPara) << "\n";
    }
}
// 将 形如"/* xxx xxxx        */ xxxxxx" \
格式化为 pair{xxx xxxx, xxxxxx} \
如果没有 注释 first = NULL
Proporty StdPara::formatToKeyValue(const std::string &text)
{
}

StdPara::~StdPara()
{
    for (auto &para : mSonParas)
    {
        delete para;
        para = nullptr;
    }
}