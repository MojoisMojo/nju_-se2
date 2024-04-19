#ifndef PROCESS_MANAGER_H
#define PROCESS_MANAGER_H
#include "Constant.h"
class BasePara;
class ProcessManager
{
    std::unordered_map<std::string, BasePara *> mVariblesMap;
public:
    ProcessManager();
};
#endif