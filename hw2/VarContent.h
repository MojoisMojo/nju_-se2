#ifndef VARCONTENT_H
#define VARCONTENT_H
#include "Constant.h"
#include "ParaContent.h"

class VarContent:public ParaContent{
public:
    VarContent(std::istream&);
};
#endif