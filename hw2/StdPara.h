#ifndef STD_PARA_H
#define STD_PARA_H
#include "BasePara.h"
class StdPara : public BasePara
{
protected:
    Properties mParaProperties;
    std::vector<BasePara *> mSonParas;
    std::vector<Content> mParaContents;

protected:
    virtual bool filter(ParaType);
    virtual bool filter(BasePara *);
    static Property formatToKeyValue(const std::string &);
    static void Skip(std::istream &);
    virtual ProcessCode processLine(std::istream &, const std::string &);
    virtual void processSubPara(std::istream &, ParaType);
    virtual std::ostream &print(std::ostream &) override;
    friend std::ostream&operator<<(std::ostream & , StdPara & );

public:
    virtual void read(std::istream &) override;
    StdPara(ParaType, BasePara *);
    ~StdPara();
};
#endif