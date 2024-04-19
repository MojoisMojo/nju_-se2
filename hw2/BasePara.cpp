#include "Constant.h"
#include "BasePara.h"
BasePara::BasePara(){
    
}
BasePara::BasePara(ParaType pType, BasePara *pFather = nullptr)
    : pType(pType), pFather(pFather)
{
}
BasePara::~BasePara()
{
}
