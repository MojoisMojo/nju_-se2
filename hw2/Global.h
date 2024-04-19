#ifndef GLOBAL_H
#define GLOBAL_H
#include "Constant.h"
class BasePara;
class Global
{
protected:
    std::unordered_map<std::string, BasePara *> mVariblesMap;

public:
    Global();
};

#endif