#ifndef VARCONTENT_H
#define VARCONTENT_H
#include "Constant.h"
#include "ParaContent.h"

class VarContent:public ParaContent{
protected:
    void processLine(const std::string &) override;
    bool filter(const std::string &) override;
public:
    VarContent(std::istream&);
};
#endif