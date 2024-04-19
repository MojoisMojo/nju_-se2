#ifndef PARACONTENT_H
#define PARACONTENT_H
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
    StdPara(std::istream &, ParaType, BasePara *);
    ~StdPara();
};
#endif