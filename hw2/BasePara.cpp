#include "Constant.h"
#include "BasePara.h"
BasePara::BasePara()
{
}
BasePara::BasePara(ParaType pType, BasePara *pFather = nullptr)
    : mParaType(pType), mParaFather(pFather)
{}
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
std::ostream& BasePara::print(std::ostream& os){
    return os << "ParaType: " << PARA_TYPE_STRINGS[(int)mParaType];
}

std::ostream&operator<<(std::ostream& os,BasePara & para){
    return para.print(os);
}

BasePara::~BasePara()
{}
