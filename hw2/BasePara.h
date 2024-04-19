#ifndef PARAGRAPH_H
#define PARAGRAPH_H
#include "Constant.h"
   class BasePara
{
protected:
    ParaType pType;
    BasePara *pFather;
public:
    BasePara();
    BasePara(std::istream &, ParaType, BasePara *);
    ~BasePara();
};

#endif