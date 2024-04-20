#ifndef STD_PARA_H
#define STD_PARA_H
#include "Constant.h"
#include "BasePara.h"
class StdPara : public BasePara
{
protected:
    Proporties mParaProporties;
    std::vector<BasePara *> mSonParas;
    std::vector<Content> mParaContents;

protected:
    static Proporty formatToKeyValue(const std::string &);
    virtual ProcessCode processLine(std::istream &fin, const std::string &);
    virtual bool filter(ParaType);
    virtual std::ostream &print(std::ostream &) override;

public:
    StdPara(std::istream &, ParaType, BasePara *);
    ~StdPara();
};
#endif