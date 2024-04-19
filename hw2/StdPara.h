#ifndef PARACONTENT_H
#define PARACONTENT_H
#include "Constant.h"
#include "BasePara.h"
class StdPara
{
protected:
    Proporty paraProporties;
    std::vector<BasePara *> paraSonParas;
    std::vector<Content> paraContents;
    virtual ProcessCode processLine(const std::string &);
    virtual bool filter(ParaType);

public:
    StdPara();
    StdPara(std::istream &);
    ~StdPara();
};
#endif