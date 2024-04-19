#ifndef VARCONTENT_H
#define VARCONTENT_H
#include "Constant.h"
#include "ParaContent.h"

class VarContent:public ParaContent{
protected:
    std::string varName;
    std::string varIdentifier;
    ProcessCode processLine(const std::string &) override;
    bool filter(ParaType) override;
public:
    VarContent(std::istream&);
    ~VarContent();
};
#endif