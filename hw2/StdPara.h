#ifndef STD_PARA_H
#define STD_PARA_H
#include "Constant.h"
#include "BasePara.h"
class StdPara:public BasePara
{
protected:
    Proporty paraProporties;
    std::vector<BasePara *> paraSonParas;
    std::vector<Content> paraContents;
    virtual ProcessCode processLine(const std::string &);
    virtual bool filter(ParaType);

public:
    StdPara(ParaType, BasePara *);
    ~StdPara();
};
#endif