#include "BasePara.h"
BasePara::BasePara(ParaType pType = ParaType::PARA_UNDEFINED, BasePara *pFather = nullptr)
    : mParaType(pType), mParaFather(pFather)
{
}
void BasePara::read(std::istream &fin)
{
}

bool BasePara::isBegin(const std::string &str)
{
    return str.substr(1, 5) == "begin";
}
bool BasePara::isEnd(const std::string &str)
{
    return str.substr(1, 3) == "end";
}
ParaType BasePara::string2ParaType(const std::string &paraTypeString)
{
    for (int i = 0; i < PARA_TYPE_NUMBER; ++i)
    {
        if (PARA_TYPE_STRINGS[i] == paraTypeString)
        {
            return (ParaType)i;
        }
    }
    return ParaType::PARA_UNDEFINED;
}
ParaType BasePara::getParaType() const
{
    return mParaType;
}
BasePara *BasePara::getParaFather() const
{
    return mParaFather;
}
std::ostream &BasePara::print(std::ostream &os)
{
    return os << "ParaType: " << PARA_TYPE_STRINGS[(int)mParaType];
}

std::ostream &operator<<(std::ostream &os, BasePara &para)
{
    return para.print(os);
}

BasePara::~BasePara()
{
}
