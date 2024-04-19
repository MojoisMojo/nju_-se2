#include "Constant.h"
#include "BasePara.h"
BasePara::BasePara(){
    
}
BasePara::BasePara(std::istream &is, ParaType pType, BasePara *pFather = nullptr)
    : pType(pType), pFather(pFather)
{
}
BasePara::~BasePara()
{
}
