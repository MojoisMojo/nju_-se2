#ifndef BASE_PARA_H
#define BASE_PARA_H
#include "Constant.h"
   class BasePara
{
protected:
    ParaType pType;
    BasePara *pFather;
public:
    BasePara();
    BasePara(ParaType, BasePara *);
    ~BasePara();
};

#endif