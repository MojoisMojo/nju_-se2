#ifndef GLOBAL_H
#define GLOBAL_H
#include "Constant.h"
class Paragraph;
class Global
{
protected:
    std::unordered_map<std::string,Paragraph *> mVariblesMap;
public:
    Global();
};

#endif