#include "StdPara.h"
StdPara::StdPara(ParaType pType, BasePara *pFather = nullptr)
    : BasePara(pType, pFather) {}

void StdPara::read(std::istream &fin)
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
        ProcessCode result = processLine(fin, line);
        if (result == ProcessCode::PROCESS_SKIP)
        {
            std::cerr << "Skip!\n";
            Skip(fin);
        }
        else if (result != ProcessCode::PROCESS_CONTINUE)
        {
            return;
        }
    }
}

void StdPara::Skip(std::istream &fin)
{
    int begin = 1;
    std::string line;
    while (begin && getline(fin, line))
    {
        myTrim(line);
        if (isBegin(line))
        {
            ++begin;
        }
        else if (isEnd(line))
        {
            --begin;
        }
    }
}
ProcessCode StdPara::processLine(std::istream &fin, const std::string &line)
{
    if (isBegin(line)) // begin
    {
        std::stringstream sline(line.substr(6));
        std::string stype;
        sline >> stype;
        ParaType sonType = string2ParaType(stype);
        if (filter(sonType)) // need to read
        {
            processSubPara(fin, sonType);
            return ProcessCode::PROCESS_CONTINUE;
        }
        return ProcessCode::PROCESS_SKIP;
    }
    else if (isEnd(line)) // end
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
            mParaProperties[p.first] = p.second;
        }
    }
    return ProcessCode::PROCESS_CONTINUE;
}

void StdPara::processSubPara(std::istream &fin, ParaType subPType)
{
    StdPara *sonPara = new StdPara(subPType, this);
    sonPara->read(fin);  // read
    if (filter(sonPara)) // check
    {
        std::cerr << "Add!\n";
        mSonParas.push_back(sonPara);
    }
    else
    {
        std::cerr << "Delete!\n";
        delete sonPara;
    }
}

bool StdPara::filter(ParaType pType)
{
    return true;
}
bool StdPara::filter(BasePara *para)
{
    return true;
}

std::ostream &StdPara::print(std::ostream &os)
{
    os << "ParaType: " << PARA_TYPE_STRINGS[(int)mParaType] << "\n";
    for (auto &[key, value] : mParaProperties)
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
    return os;
}
// 将 形如"/* xxx xxxx        */ xxxxxx" \
格式化为 pair{xxx xxxx, xxxxxx} \
如果没有 /**/ 则将first=""
Property StdPara::formatToKeyValue(const std::string &text)
{
    Property result;
    // 查找注释的起始位置
    size_t beginPos = text.find("/*");
    if (beginPos != std::string::npos)
    {
        size_t endPos = text.find("*/", beginPos + 2);
        if (endPos != std::string::npos)
        {
            std::string comment = text.substr(beginPos + 2, endPos - beginPos - 2);
            std::string content = text.substr(endPos + 2);
            myTrim(comment);
            myTrim(content);
            result = {comment, content};
        }
        else
        {
            result = std::make_pair("", "");
        }
    }
    else
    {
        std::string value = text;
        myTrim(value);
        int i = 0, length = value.size();
        while (length > i && value[i] == '\"')
        {
            ++i;
        }
        value.erase(0, i);
        i = value.size() - 1;
        length = value.size();
        while (0 <= i && value[i] == '\"')
        {
            --i;
        }
        value.erase(i + 1, length - i - 1);

        result = std::make_pair("", value);
    }

    return result;
}

StdPara::~StdPara()
{
    for (auto &para : mSonParas)
    {
        delete para;
        para = nullptr;
    }
}

std::ostream &operator<<(std::ostream &os, StdPara &par)
{
    return par.print(os);
}