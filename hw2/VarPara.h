#ifndef VARCONTENT_H
#define VARCONTENT_H
#include "Constant.h"
#include "StdPara.h"

class VarPara : public StdPara
{
protected:
    std::string varName;
    std::string varIdentifier;

protected:
    ProcessCode processLine(const std::string &) override;
    bool filter(ParaType) override;

public:
    VarPara(std::istream &);
    ~VarPara();
};
#endif